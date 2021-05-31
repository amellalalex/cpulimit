/**
 * @file cpulimit.h
 * @author Alex Amellal (loris@alexamellal.com)
 * @brief Custom header to link existing cpulimit codebase to external project
 * @version 0.1
 * @date 2021-05-31
 * 
 * @copyright Galaxia Mission Systems (c) 2021
 * 
 */

#ifndef __CPULIMIT_CPULIMIT_H__
#define __CPULIMIT_CPULIMIT_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <time.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
// #include <sys/sysctl.h>
#include <libgen.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "process_group.h"
#include "list.h"

#ifdef HAVE_SYS_SYSINFO_H
#include <sys/sysinfo.h>
#endif

#ifdef __APPLE__
#include "memrchr.c"
#endif

//some useful macro
#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

//control time slot in microseconds
//each slot is splitted in a working slice and a sleeping slice
//TODO: make it adaptive, based on the actual system load
#define TIME_SLOT 100000

#define MAX_PRIORITY -10

void limit_process(pid_t pid, double limit, int include_children);

#endif