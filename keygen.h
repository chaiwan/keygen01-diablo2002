/* keygen.h */

/*** equates ***/

/* meta */
#define PROG_NAME         "keygen"
#define PROG_VERSION      "1.0a"
#define PROG_AUTHOR       "chaiwan"
#define PROG_RELEASE      "2018"
#define PROG_NAME_LOCALIZED       "Keygen #1"
#define PROG_DESCRIPTION_LOCALIZED  "Solution for diablo2002's Crackme #1"
#define PROG_VERSION_LOCALIZED    "v" PROG_VERSION
#define PROG_AUTHOR_LOCALIZED     PROG_AUTHOR
#define PROG_BANNER_LOCALIZED     PROG_NAME_LOCALIZED " - " PROG_VERSION_LOCALIZED
#define PROG_COPYRIGHT_LOCALIZED  "Copyright (c)" " " PROG_RELEASE ", by " PROG_AUTHOR_LOCALIZED "." " " "All rights reserved."
#define PROG_LICENSE_LOCALIZED    \
"     This program is free software; you can redistribute it and/or modify\n\
     it under the terms of the GNU General Public License as published by\n\
     the Free Software Foundation; either version 2 of the License, or\n\
     (at your option) any later version.\n\
 \n\
     This program is distributed in the hope that it will be useful,\n\
     but WITHOUT ANY WARRANTY; without even the implied warranty of\n\
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n\
     GNU General Public License for more details.\n\
 \n\
     You should have received a copy of the GNU General Public License\n\
     along with this program; if not, write to the Free Software\n\
     Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA"

/* operation */
#define KEYGEN_NAME_LEN   5
#define KEYGEN_SERIAL_LEN 10

/* opt: help */
#define OPT_HELP_ABOUT    "Display this usage message and exit"
#define OPT_HELP_LONG     "help"
#define OPT_HELP_SHORT    'h'
#define SZ_OPT_HELP_SHORT "h"
#define OPT_HELP_HASARG   no_argument

/* opt: version */
#define OPT_VERSION_ABOUT    "Version and copyright information"
#define OPT_VERSION_LONG     "version"
#define OPT_VERSION_SHORT    'v'
#define SZ_OPT_VERSION_SHORT "v"
#define OPT_VERSION_HASARG   no_argument

/* opt: generate */
#define OPT_GENERATE_ABOUT  "Generate a serial from \"name\""
#define OPT_GENERATE_LONG   "generate"
#define OPT_GENERATE_SHORT  'g'
#define SZ_OPT_GENERATE_SHORT  "g"
#define OPT_GENERATE_HASARG optional_argument

/* msg: usage */
#define PROG_USAGE_MESSAGE "Usage:\t" PROG_NAME " [OPTION] [TEXT]\n" \
                      "  " "-" SZ_OPT_GENERATE_SHORT "\t" OPT_GENERATE_ABOUT "\n" \
                      "  " "-" SZ_OPT_HELP_SHORT   "\t" OPT_HELP_ABOUT "\n" \
                      "  " "-" SZ_OPT_VERSION_SHORT   "\t" OPT_VERSION_ABOUT "\n"
#define PROG_HELP_MESSAGE "\n" PROG_USAGE_MESSAGE

/* msg: version */
#define PROG_ABOUT_MESSAGE PROG_BANNER_LOCALIZED "\n" "     " PROG_DESCRIPTION_LOCALIZED "\n\n" PROG_COPYRIGHT_LOCALIZED
#define PROG_VERSION_MESSAGE "\n" PROG_ABOUT_MESSAGE "\n\n" PROG_LICENSE_LOCALIZED "\n"

/* errors */
#define PROG_EXEC_ERROR_MESSAGE "ERROR!"
#define PROG_EXEC_ERROR_MESSAGE_NAME_LEN "Name must be 5 characters."
  #define SZ_EXEC_ERROR_NAME_LEN  PROG_EXEC_ERROR_MESSAGE " " PROG_EXEC_ERROR_MESSAGE_NAME_LEN

/* messages */
#define PROG_EXEC_INFO_MESSAGE_TRUNCATING_NAME "Truncating excessive characters from name..."

/* masks */
#define OPTS_MASK_DEFAULT  0
#define OPTS_MASK_NOARGS 1
#define OPTS_MASK_HELP    1
#define OPTS_MASK_VERSION 2
#define OPTS_MASK_GENERATE  4

