#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void UpDate();
void OutPut();
int main(){

 int nstep,nline;
 {
  FILE *fp;
  int val;
  char chr[20];
  if((fp=fopen("data.in","r"))==NULL){puts("Err:No icon.in");exit(1);}
  while(fscanf(fp,"%s %d",chr,&val)!=EOF){
   if(!strcmp(chr,"nstep"))nstep=val;
   else if(!strcmp(chr,"nline"))nline=val;
   else{printf("Err:What is %s ?\n",chr);exit(1);}
  }
  fclose(fp);
 }

 int Val[nline][nline];
 {
  int iline,jline;
  for(iline=0;iline<nline;iline++)
   for(jline=0;jline<nline;jline++)
    Val[iline][jline]=0;
  Val[4][3]=1;
  Val[3][4]=1;
  Val[4][4]=1;
  Val[4][5]=1;
  Val[5][5]=1;
 }

 {
  int istep;
  for(istep=0;istep<nstep;istep++){
   UpDate(nline,nstep,Val);
   OutPut(nline,istep,Val);
  }
 }
 return 0;
}

void UpDate(int nline,int nstep,int Val[nline][nline]){
 int iline,jline,nlife,Old[nline][nline],left,right,above,bottom;
 for(iline=0;iline<nline;iline++)
  for(jline=0;jline<nline;jline++){
   Old[iline][jline]=Val[iline][jline];
  }
 for(iline=0;iline<nline;iline++)
  for(jline=0;jline<nline;jline++){
   left=   iline==0? nline-1:iline-1;
   right=  iline==nline-1? 0:iline+1;
   bottom= jline==0? nline-1:jline-1;
   above=  jline==nline-1? 0:jline+1;
   nlife= Old[left][bottom]
         +Old[left][jline]
         +Old[left][above]
         +Old[iline][bottom]
         +Old[iline][above]
         +Old[right][bottom]
         +Old[right][jline]
         +Old[right][above];
   if(nlife==3)Val[iline][jline]=1;
   if(nlife<=1||nlife>=4)Val[iline][jline]=0;
  }
}

void OutPut(int nline,int istep,int Val[nline][nline]){
 FILE *fp;
 int iline,jline;
 char fname[200];
 sprintf(fname,"%03d.dat",istep);
 fp=fopen(fname,"w");
 for(iline=0;iline<nline;iline++){
  for(jline=0;jline<nline;jline++)fprintf(fp,"%1d ",Val[iline][jline]);
  fprintf(fp,"\n");
 }
 fclose(fp);
}
