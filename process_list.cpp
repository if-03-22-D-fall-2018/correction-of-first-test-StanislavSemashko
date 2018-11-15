/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			grade_list.c
 * Author:			P. Bauer
 * Due Date:		November 18, 2010
 * ----------------------------------------------------------
 * Description:
 * Implementation of grade_list.h.
 * ----------------------------------------------------------
 */
// #include <stdlib.h>
// #include "shortcut.h"
// #include "test_process_list.h"
#include "process_list.h"
#include "stdio.h"



void init_process_list(ProcessList* pl)
{
   pl->length = 0;
}

bool 	add_entry (ProcessList *pl, struct ProcessListEntry *e)
{
   if (pl->length < MAX_LIST_ENTRIES)
   {
     pl->processes[pl->length] = e;
     pl->length +=1;
     return true;
   }
  return false;
}
int	get_length (const ProcessList *pl)
{
  return pl->length;
}
bool 	add_entries (ProcessList *pl, struct ProcessListEntry *e[], int n)
{
  if (pl->length + n <= MAX_LIST_ENTRIES)
  {
    int x = pl->length; // eine locale variable hinzugefügt
    for (int i = pl->length; i < n + x; i++) //if bedienung geändert
    {
          pl->processes[i] = e[i-x]; //zugriff auf e geändert
          pl->length += 1;
    }
    return true;
  }
  return false;

}

int 	get_process_with_id (const ProcessList *pl, int id, struct ProcessListEntry *result_list[])
{
  int found = 0;
  int x= pl->length;
  for (int i = 0; i < x && i < MAX_LIST_ENTRIES && x != 0 ; i++)
  {
    if (pl->processes[i] != 0 && pl->processes[i]->pid == id) //weitere if bedienung hinzugefügt
    {
        result_list[found] = pl->processes[i];
        found+=1;
      //  x-=1;
    }
  }
     return found ;
}



int get_processes_with_state (const ProcessList *pl, enum ProcessState state, struct ProcessListEntry *result_list[])
{

  int found = 1;
  int x= pl->length;        // eine neue variable angelegt
  for (int i = 0; i < x && x != 0 ; i++)     //weitere bedienung hinzugefügt, nur bis dahin gehen wie viel element sind
  {
    if ( pl->processes[i] != 0 && pl->processes[i]->state == state) //weitere if bedienung hinzugefügt
    {
      result_list[found-1] = pl->processes[i];       // strichpunkt entfernt
      found +=1;
    }
  }
  return found-1;
}

struct ProcessListEntry * 	get_process_with_highest_cpu_consumption (const ProcessList *pl)
{
  int highest_time = 0;
  if (pl->length != 0)
  {
    for (int i = 0; i < pl->length-1; i++) // for bedienung hinzugefügt
    {
      if (i+1 <= MAX_LIST_ENTRIES && pl->processes[highest_time]->time < pl->processes[i+1]->time) // if bedienung verändert
      {
        highest_time = i +1;         //pl->processes[i]->time; // i+1
      }
                                                    // else removed
                                    //pl->processes[i+1]->time;
    }
      return pl->processes[highest_time]; //return eine klammer nach oben verschoben
  }
  return 0;   // neues return hinzugefügt

 }

struct ProcessListEntry * 	get_process_with_lowest_cpu_consumption (const ProcessList *pl)
{
  int highest_time = 0;
  if (pl->length != 0)
  {
    for (int i = 0; i < pl->length-1; i++) // for bedienung hinzugefügt
    {
      if (i+1 <= MAX_LIST_ENTRIES && pl->processes[highest_time]->time > pl->processes[i+1]->time) // if bedienung verändert
      {
        highest_time = i +1;         //pl->processes[i]->time; // i+1
      }
                                                    // else removed
                                    //pl->processes[i+1]->time;
    }
      return pl->processes[highest_time]; //return eine klammer nach oben verschoben
  }
  return 0;   // neues return hinzugefügt

}

int 	get_top_n_processes_cpu (const ProcessList *pl, int n, struct ProcessListEntry *result_list[])
{
  return 0;
}

int 	get_bottom_n_processes_cpu (const ProcessList *pl, int n, struct ProcessListEntry *result_list[])
{
  return 0;
}
