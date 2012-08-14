/*
 * =============================================================================
 *
 *       Filename:  page_formatter.h
 *
 *    Description:  Page formatter module.
 *
 *    Exercise was vague, so I've assumed that
 *    1: Files are text only
 *    2: Formatting is done using primitive markup tags
 *    2: Line 0 contains only the header, if one exists, enclosed in tags
 *       <header></header>
 *    3: A new page is indicated by the tag <newpage>
 *    4: When page(void) is called, a newpage is created immediately after
 *       the current file position
 *    5: When print_line(char *) is called, it writes the string immediately
 *       after the current file position.  It will NOT automatically
 *       append a newline to the end of the string.
 *    6: If either open_file or close_file fails, program will exit with error.
 *
 *        Version:  1.0
 *        Created:  12-08-13 08:16:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Kydd (), akydd@ualberta.net
 *        Company:  
 *
 * =============================================================================
 */

#define BUFFER_SIZE (16 * 1024) /* max 16K chars */

void open_file(char *);

void define_header(char *);

void print_line(char *);

void page(void);

void close_file(void);
