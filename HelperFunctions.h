/*
 * Created by:
 * Matthew Moltzau and Michael Hedrick
 * Spring 2018
 */

#ifndef HELPER_FUNCTIONS_
#define HELPER_FUNCTIONS_

/*
 * -----------------------------------------------
 * Dynamic String Copy
 * -----------------------------------------------
 * This method will dynamically allocate a new
 * c string using the length of another one, then
 * copy that string over.
 *
 * This method accepts a pointer to a pointer so that
 * the memory allocation performed does not disappear
 * after the method returns.
 */
void dynamicStrCpy(char** newStr, char* oldStr);

#endif