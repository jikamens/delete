/*
 * $Source: /afs/dev.mit.edu/source/repository/athena/bin/delete/directories.h,v $
 * $Author: jik $
 * $Header: /afs/dev.mit.edu/source/repository/athena/bin/delete/directories.h,v 1.8 1989-11-06 19:54:20 jik Exp $
 * 
 * This file is part of a package including delete, undelete,
 * lsdel, expunge and purge.  The software suite is meant as a
 * replacement for rm which allows for file recovery.
 * 
 * Copyright (c) 1989 by the Massachusetts Institute of Technology.
 * For copying and distribution information, see the file "mit-copyright.h."
 */

#include "mit-copyright.h"

typedef short Boolean;
#define True			(Boolean) 1
#define False			(Boolean) 0


#define blk_to_k(x)		(x * DEV_BSIZE / 1024)

#define FOLLOW_LINKS		1
#define DONT_FOLLOW_LINKS	0

#define DIR_MATCH		1
#define DIR_NO_MATCH		0
     
typedef struct filrec {
     char name[MAXNAMLEN];
     struct filrec *previous;
     struct filrec *parent;
     struct filrec *dirs;
     struct filrec *files;
     struct filrec *next;
     Boolean specified;
     Boolean freed;
     struct stat specs;
} filerec;



int add_directory_to_parent();
int add_file_to_parent();
int add_path_to_tree();
int find_child();
filerec *first_in_directory();
filerec *first_specified_in_directory();
filerec *get_cwd_tree();
filerec *get_root_tree();
filerec *next_directory();
filerec *next_in_directory();
filerec *next_leaf();
filerec *next_specified_directory();
filerec *next_specified_in_directory();
filerec *next_specified_leaf();

int get_leaf_path();
int accumulate_names();

void free_leaf();
