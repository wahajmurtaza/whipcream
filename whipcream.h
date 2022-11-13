
#ifndef __WHIPCREAM_H__
#define __WHIPCREAM_H__

#include <string.h>

// #define PRINTS_DISABLED
// #define CUSTOM_DEBUG
// #define COLORS_DISABLED

#ifndef DEFAULT_FMT
/*! Default print format used to print when wc is called as a single parameter */
#define DEFAULT_FMT "%10d"
#endif

#ifndef CUSTOM_BUFFER_SIZE
/*! Buffer Size to Print Message (when used custom print function) */
#define CUSTOM_BUFFER_SIZE 200
#endif


/*! Max string size for printing the file name */
#define _FILE_NAME_BUFF_SIZE 30
/*! Max string size for printing the variable name */
#define _VAR_NAME_BUFF_SIZE 20



#ifndef COLORS_DISABLED

#ifndef _FILE_COLOR
/*! Color for printing the file name */
#define _FILE_COLOR "\033[0;36m"  // CYAN
#endif /*_FILE_COLOR */

#ifndef _VAR_COLOR
/*! Color for printing the variable name */
#define _VAR_COLOR "\033[0;33m" // YELLOW
#endif /*_VAR_COLOR */

#ifndef _VALUE_COLOR
/*! Color for printing the variable value */
#define _VALUE_COLOR "\033[0;32m" // GREEN
#endif /*_VALUE_COLOR */

/*! Color reset / end */
#define _RESET_COLOR "\033[0m" // RESET

#else /*COLORS_DISABLED*/

#define _FILE_COLOR
#define _VAR_COLOR
#define _RESET_COLOR
#define _VALUE_COLOR

#endif /*COLORS_DISABLED*/


#ifdef PRINTS_DISABLED
	
	#define wc(...) do{__VA_ARGS__ ;}while(0)  // executes the function / expression that was passed

#else

#define wc(...) _WC(_, ##__VA_ARGS__)
#define _WC(...) __WC(__VA_ARGS__, __2_PARAM, __1_PARAM, __0_PARAM)(__VA_ARGS__)
#define __WC(_2, _1, _0, _nargs, ...) _WC ##_nargs
#define _WC__2_PARAM(_, _val, _fmt) do{ \
		char _var_name[_VAR_NAME_BUFF_SIZE], _file_name[_FILE_NAME_BUFF_SIZE];\
		snprintf(_var_name, _VAR_NAME_BUFF_SIZE, "%s", #_val);\
		snprintf(_file_name, _FILE_NAME_BUFF_SIZE, _FILE_COLOR"%s [:%d]", __FILE__, __LINE__);\
		RETURN_OUTPUT("%-*s : "_VAR_COLOR"%-*s"_RESET_COLOR" = "_VALUE_COLOR _fmt _RESET_COLOR"\n" , _FILE_NAME_BUFF_SIZE, _file_name, _VAR_NAME_BUFF_SIZE, _var_name, _val);\
	}while(0)
#define _WC__1_PARAM(_, _val) do{ \
		char _var_name[_VAR_NAME_BUFF_SIZE], _file_name[_FILE_NAME_BUFF_SIZE];\
		snprintf(_var_name, _VAR_NAME_BUFF_SIZE, "%s", #_val);\
		snprintf(_file_name, _FILE_NAME_BUFF_SIZE, _FILE_COLOR"%s [:%d]", __FILE__, __LINE__);\
		RETURN_OUTPUT("%-*s : " _VAR_COLOR "%-*s" _RESET_COLOR " = " _VALUE_COLOR DEFAULT_FMT _RESET_COLOR"\n" , _FILE_NAME_BUFF_SIZE, _file_name, _VAR_NAME_BUFF_SIZE, _var_name, _val);\
	}while(0)
#define _WC__0_PARAM(_) do{RETURN_OUTPUT(_FILE_COLOR "%s [:%d]" _RESET_COLOR " %s()\n", __FILE__, __LINE__, __func__);}while(0)




#ifdef CUSTOM_DEBUG

extern int custom_debug(char *);
#define RETURN_OUTPUT(...) do{char __out_str[CUSTOM_BUFFER_SIZE]; snprintf(__out_str, CUSTOM_BUFFER_SIZE, __VA_ARGS__); custom_debug(__out_str);}while(0)

#else

#define RETURN_OUTPUT(...) printf(__VA_ARGS__)

#endif /*CUSTOM_DEBUG*/



#endif // PRINT_ENABLED


#endif // __WHIPCREAM_H__