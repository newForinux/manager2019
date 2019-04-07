#include "user.h"
#include "menu.h"

int main(int argc, char* argv[]) {
  LOGIN* userlist[100]; // 사용자목록 포인터 배열 (최대 100)
  int is_login=0; // 로그인 여부 (0 NO, 1 Yes)
  int menu_id, new_file;
  char command_user[100];
  int count = 0, *count_point;
  int ch = 0;
  if (argc != 2) {
    printf("Usage : manager <datafile>\n");
    return 0;
  }
  else {
    if (!fopen(argv[1], "r")) {
	printf ("%s file not exist! make anyway? (Yes 1, No 2) >> ", argv[1]);
	scanf ("%d", &new_file);
	if (new_file == 2)
	    return 0;
    }
    else
	count = load_file (userlist, argv[1]); 
  }
  count_point = &count;
  printf ("Welcome!!\n");

  while(1){
    if (is_login != 1) {
	printf ("> ");
	scanf ("%s", command_user);
	if(strcmp(command_user, "login")==0) is_login = login(userlist, count);
	else if(strcmp(command_user, "join")==0) join(userlist, count_point);
	else if(strcmp(command_user, "list")==0) list_user(userlist, count);
	else if(strcmp(command_user, "exit")==0) {
	    save_file(userlist, count, argv[1]);
	    return 0;
	}
	else
	    printf ("No such command!\n");
    }
    else if (is_login == 1) {
	printf ("# ");
	if (ch == 0) {
	    getchar();
	    ch++;
	}
	fgets (command_user, 99, stdin);
	if (strncmp(command_user, "logout", 6) == 0)
	    logout(&is_login);
	printf ("%s", command_user);
    }
  }
  return 0;
}
