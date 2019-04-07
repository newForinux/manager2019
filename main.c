#include "user.h"
#include "menu.h"

int main(int argc, char* argv[]) {
  LOGIN* userlist[100]; // 사용자목록 포인터 배열 (최대 100)
  int is_login=0; // 로그인 여부 (0 NO, 1 Yes)
  int menu_id;
  int new_file;
  FILE * fp;
  if (argc != 2) {
    printf("Usage : manager <datafile>\n");
    return 0;
  }
  else {
    printf ("%s file not exist! make anyway? (Yes 1, No 2) >> ", argv[1]);
    scanf ("%d", &new_file);
    if (new_file == 1)
	fp = fopen (argv[1], "w");
    else
	return 0;
  }
  int count = load_file(userlist, argv[1]);
  while(1){
    if(is_login==0) is_login = login(userlist, count);
    menu_id = ask_menu(is_login); // 현재 로그인 되었는지의 여부를 파라미터로 알려야 한다.
    if(menu_id==1) join(userlist, count);
    else if (menu_id==2) is_login = login(userlist, count);
    else if (menu_id==3) logout(&is_login);
    else break;
  }
  save_file(userlist, count, argv[1]);
  fclose(fp);
  return 0;
}
