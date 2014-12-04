#include <stdio.h>
#include <string.h>
#include <direct.h>
#include <stdlib.h>

/*
	When calling the program, use -r to pass relative paths as parameters.
	In all other situation, just write the parameter.

	Examples:
		Assuming hello.ceu and this program (called ceu)
		are in the folder C:\Users\John\Desktop\ceu_for_windows\,
		both commands should compile hello.ceu.

		ceuc -r hello.ceu
		ceuc C:\Users\John\Desktop\ceu_for_windows\hello.ceu
*/
int main(int argn, char* argc[])
{
	char current_dir[1000];
	char cmd[100000] = "";
	int i;

	_getcwd(current_dir,1000);

	for(i=1;i<argn;i++)
	{
		strcpy(cmd,"");
		strcat(cmd,"copy /Y \"");
		strcat(cmd,argc[i]);
		strcat(cmd,"\" ceu-sdl");
		printf("\n****************************\n");
		printf("%s\n",cmd);
		system(cmd);
	}

	// command start reference: http://ss64.com/nt/start.html

	strcpy(cmd,"");
	strcat(cmd,"start \"\" /D\"");
	strcat(cmd,current_dir);
	strcat(cmd,"\\ceu-sdl\" /B /W lua5.1\\bin\\lua.exe ceu");
	for(i=1;i<argn;i++)
	{
		strcat(cmd," \"");
		strcat(cmd,argc[i]);
		strcat(cmd,"\"");
	}
	printf("\n****************************\n");
	printf("%s\n",cmd);
	system(cmd);

	if(argn > 1)
	{
		strcpy(cmd,"");
		strcat(cmd,"mingw\\bin\\gcc -m32");
		strcat(cmd," ceu-sdl\\main.c -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_mixer -lSDL2_image");
		printf("\n****************************\n");
		printf("%s\n",cmd);
		system(cmd);
	}

	for(i=1;i<argn;i++)
	{
		strcpy(cmd,"");
		strcat(cmd,"del ");
		strcat(cmd," \"ceu-sdl\\");
		strcat(cmd,argc[i]);
		strcat(cmd,"\"");
		printf("\n****************************\n");
		printf("%s\n",cmd);
		system(cmd);
	}

/*
	for(i=1;i<argn;i++)
	{
		if(strcmp(argc[i],"-r")==0)
		{
			i++;
			if(i>=argn)
			{
				printf("\n****************************\n");
				printf("ERROR: An relative path must be passed after \'-r\'.\n");
				exit(1);
			}
			strcat(cmd," \"");
			strcat(cmd,current_dir);
			strcat(cmd,"\\");
			strcat(cmd,argc[i]);
			strcat(cmd,"\"");
		}
		else
		{
			strcat(cmd," \"");
			strcat(cmd,argc[i]);
			strcat(cmd,"\"");
		}
	}
	system(cmd);
*/

	return 0;
}