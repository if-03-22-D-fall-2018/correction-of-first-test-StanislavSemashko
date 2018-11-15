/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			process_list.h
 * Author:			P. Bauer
 * Due Date:		December 3, 2010
 * ----------------------------------------------------------
 * Description:
 * process_list.h definiert Funktionen zur Verwaltung von UNIX
 * Prozesseinträgen.
 * ----------------------------------------------------------
 */
#include <stdbool.h>
#ifndef ___TEST_PROCESS_LIST_H
#define ___TEST_PROCESS_LIST_H

#define MAX_LIST_ENTRIES 13

enum ProcessState
{
  RUNNING,SLEEPING,IDLE,ZOMBIE,SWAPPEDOUT,STOPPED
};


struct ProcessListEntry
{
  int pid;
  const char* process_name;
  int cpu_usage;
  int time;
  int threads;
  long vsize;
  enum ProcessState state;
};

struct ProcessList
{
  int length;
  struct ProcessListEntry* processes[MAX_LIST_ENTRIES];
};


void init_process_list(ProcessList* pl);

int 	get_length (const ProcessList *pl);

bool 	add_entry (ProcessList *pl, struct ProcessListEntry *e);

bool 	add_entries (ProcessList *pl, struct ProcessListEntry *e[], int n);

int 	get_process_with_id (const ProcessList *pl, int id, struct ProcessListEntry *result_list[]);

int 	get_processes_with_state (const ProcessList *pl, enum ProcessState state, struct ProcessListEntry *result_list[]);

struct ProcessListEntry * 	get_process_with_highest_cpu_consumption (const ProcessList *pl);

struct ProcessListEntry * 	get_process_with_lowest_cpu_consumption (const ProcessList *pl);

int 	get_top_n_processes_cpu (const ProcessList *pl, int n, struct ProcessListEntry *result_list[]);

int 	get_bottom_n_processes_cpu (const ProcessList *pl, int n, struct ProcessListEntry *result_list[]);



#endif
