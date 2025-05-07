#include<stdio.h>
#include<string.h>
#define MaxB 100
#define MaxF 10
 int blocks[MaxB]={0};
 char filenames[MaxF][20];
 int filestarts[MaxF];
 int filelengths[MaxF];
 int filecount=0;
  void allocatefile()
  {
      char name[20];
      int length;
      int start;
      printf("Enter file name   ");
      scanf("%s",name);
      printf("Enter file length   ");
      scanf("%d",&length);
      printf("Enter index of start block  ");
      scanf("%d",&start);
      if(start<0 || start+length>MaxB)
      {
          printf("Cannot allocate; blocks out of range\n");
          return;
      }
      for(int i=start;i<start+length;i++)
      {
          if(blocks[i]==1)
          {
              printf("Some of the intermediate blocks are occupied, cannot allocate the file\n");
              return;
          }
      }
      for(int i=start;i<start+length;i++)
      {
          blocks[i]=1;
      }
      printf("File %s has been allocated\n",name);
      strcpy(filenames[filecount],name);
      filestarts[filecount]=start;
      filelengths[filecount]=length;
      filecount++;
  }
  void seefiles()
  {
      printf("File name\tFile Start\tFile Length\n");
      for(int i=0;i<filecount;i++)
      {
        printf("%s\t\t%d\t\t%d\n",filenames[i],filestarts[i],filelengths[i]);
      }
  }
  void main()
  {
      int choice;
      printf("1.Allocate a file\n2.Display files\n3.Exit\n");
      while(1)
      {
          printf("Enter choice   ");
          scanf("  %d",&choice);
          switch(choice)
          {
              case 1:allocatefile();
              break;
              case 2:seefiles();
              break;
              case 3:exit(0);
          }
      }
  }
