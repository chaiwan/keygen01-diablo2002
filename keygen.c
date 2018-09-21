/* keygen.c */

/*
 *  Keygen #1
 *  Copyright (c) 2018, chaiwan. All rights reserved.
 *
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

/* Solution for diablo2002's Crackme #1 */

#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "keygen.h"

/*** proto ***/
void dispatch_keygen(unsigned long, char *) __attribute__((noreturn));
void dispatch_message(unsigned long, char *) __attribute__((noreturn));
void dispatch_error(unsigned long, char *, unsigned long) __attribute__((noreturn));
char *getserial(char *, const char *);

/*** .data/.const ***/
const char *sz_usage = PROG_HELP_MESSAGE;
const char *sz_about = PROG_VERSION_MESSAGE;
const char *sz_exec_error = PROG_EXEC_ERROR_MESSAGE;
const char *sz_exec_error_name_len = SZ_EXEC_ERROR_NAME_LEN;
#define SZ_OPTSTRING ":" SZ_OPT_GENERATE ":" SZ_OPT_HELP SZ_OPT_VERSION
const char *sz_optstring = SZ_OPTSTRING;

/*** proc ***/
/*
 * main
 */
int main(int argc, char *argv[]) {
  /* stack */
  int opt_tmp;
  char *sz_arg_generate;
  unsigned long fflags = 0, fflags_generate = 0;
  /* text */
  while ((opt_tmp = getopt(argc, argv, sz_optstring)) != -1) {
    switch(opt_tmp) {
    case OPT_GENERATE:
      sz_arg_generate = optarg;
      fflags |= OPTS_MASK_GENERATE;
      break;
    case OPT_HELP:
      fflags |= OPTS_MASK_HELP;
      break;
    case OPT_VERSION:
      fflags |= OPTS_MASK_VERSION;
      break;
    case ':':
      if (optopt == OPT_GENERATE) {
        fflags |= OPTS_MASK_GENERATE;
        fflags_generate |= OPTS_MASK_NOARGS;
      }
      break;
    case '?':
      if (optopt == '?') {
        fflags |= OPTS_MASK_HELP;
        break;
      }
      break;
    default: /* '?' */
      exit(EXIT_FAILURE);
    }
  }
  switch(fflags) {
    case OPTS_MASK_GENERATE:
      dispatch_keygen(fflags_generate, sz_arg_generate);
    case OPTS_MASK_HELP:
      dispatch_message(fflags, (char *)sz_usage);
    case OPTS_MASK_VERSION:
      dispatch_message(fflags, (char *)sz_about);
    default:
      dispatch_error(fflags, (char *)sz_exec_error, EXIT_FAILURE);
  }
  return 0;
}

/*
 * dispatch: keygen
 */
void dispatch_keygen(unsigned long f, char *s) {
  /* stack */
  char d[KEYGEN_SERIAL_LEN+1], *S, _S[KEYGEN_NAME_LEN+1];
  size_t slen, nread;
  /* text */
  S = _S;
  slen = strnlen(s, (KEYGEN_NAME_LEN+1));
  if (f & OPTS_MASK_NOARGS || (slen == 1 && *s == '-')) {
    nread = fread((void *)d, sizeof(char), KEYGEN_NAME_LEN, stdin);
    if (d[KEYGEN_NAME_LEN-1] == '\n' || nread < KEYGEN_NAME_LEN) {
      dispatch_error(0, (char *)sz_exec_error_name_len, PROG_EXEC_ERROR_CODE_NAME_LEN);
    }
    else {
      strncat(S, d, KEYGEN_NAME_LEN);
    }
  }
  else if (slen < KEYGEN_NAME_LEN) {
    dispatch_error(0, (char *)sz_exec_error_name_len, PROG_EXEC_ERROR_CODE_NAME_LEN);
  }
  else if (slen > KEYGEN_NAME_LEN) {
    memcpy(_S, s, KEYGEN_NAME_LEN);
  }
  else {
    S = s;
  }
  d[KEYGEN_SERIAL_LEN] = 0;
  _S[KEYGEN_NAME_LEN] = 0;
  printf("%s: %s\n", S, getserial(d, S));
  exit(EXIT_SUCCESS);
}

/*
 * getserial
 */
char *getserial(char *d, const char *s) {
  /* stack */
  char ch;
  char *seed, _seed[KEYGEN_SERIAL_LEN+1];
  unsigned long i, j;
  /* text */
  /* stage: 1 */
  seed = _seed;
  for (i=0, j=5; j; i++, j--) {
    ch = s[i];
    ch ^= 0x29;
    ch += j;
    if (ch < 'A' || ch > 'Z') {
        ch = 0x52 + j;
    }
    seed[i] = ch;
  }
  /* stage: 2 */
  seed += 5;
  for (i=0, j=5; j; i++, j--) {
    ch = s[i];
    ch ^= 0x27;
    ch += j + 1;
    if (ch < 'A' || ch > 'Z') {
      ch = 0x4d + j;
    }
    seed[i] = ch;
  }
  /* stage: 3 */
  seed -= 5;
  for (i=0, j=10; j; i++, j--) {
    ch = seed[i];
    ch += 5;
    if (ch > 'Z') {
      ch -= 0xd;
    }
    ch ^= 12;
    if (ch < 'A') {
      ch = 0x4b + i;
    }
    else if (ch > 'Z') {
      ch = 0x4b - i;
    }
    d[i] = ch;
  }
  _seed[KEYGEN_SERIAL_LEN] = 0;
  return d;
}

/*
 * dispatch: message
 */
void dispatch_message(unsigned long f, char *s) {
  /* stack */
  /* text */
  fprintf(stdout, "%s\n", s);
  exit(EXIT_SUCCESS);
}

/*
 * dispatch: error
 */
void dispatch_error(unsigned long f, char *s, unsigned long n) {
  /* stack */
  /* text */
  fprintf(stdout, "%s: (%lu)\n", s, n);
  exit(EXIT_FAILURE);
}

