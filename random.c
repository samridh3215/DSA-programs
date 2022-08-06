/*Questions:
count the  number of matches played in year 2008
count the number of times the toss winner is same as the winner of match
display total count of matches played b/w KKR and RCB
Display winner of each match played in 2016
display list of player of match where there was a match between RCB and CSK in 2010
output of all the above can be written to a file to store record of outputs in one file*/

//0.Perform Selection sort the following array. Show the array after each swap that takes place. { 30, 60, 20, 50, 40, 10 }

/*#include <stdio.h>

#include <string.h>


void main(){
	FILE *ptr = fopen("matches.csv", "r");
	int count =0;
	if(ptr==NULL)
		printf("Error!\n");
	else
		printf("Success\n");
	
	char lines[500];
	while(fgets(lines, 500, ptr)!=NULL){
		char* val = strtok(lines, ",");
		val = strtok(NULL, ",");
		if (strcmp(val, "2008")==0)
			count = count+1;
		//printf("%d", count);
	}
printf("%d\n", count);

	count = 0;
	while(fgets(lines, 500, ptr)!=NULL){
		char* tosswin = strtok(lines, ",");
		tosswin = strtok(NULL, ",");
		if (strcmp(tosswin, teamwin)==0)
			count = count+1;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	int n;
	printf("Enter N value");
	scanf("%d", &n);
	int matrix[n][n];
	printf("enter elements");
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

}	

