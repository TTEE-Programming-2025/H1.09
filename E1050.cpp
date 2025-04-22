#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void clear() {
    system("cls");
}
void showBanner() {
    puts("           =:                                                                                :=***=:         ");
    puts("           **                                                                              :*#%#####*-       ");
    puts("           +%.                               .                                            :#%%%=--+###+.     ");
    puts("           +#-              :+             :*#*.                                         .*%%#-    .-+##:    ");
    puts("           +#*              =#:          -*#%%%+                                         +#%#+        :##.   ");
    puts("          .*##              =%-        -##+-*##*                                        .#%%%.       .%%%:   ");
    puts("          .###.             +#=        -:   *#%#.                                       -#%#*       :%@@@%.  ");
    puts("          -###.             +##.            +#%#:                                       -#%#*      =%@@@@=   ");
    puts("          =#%#.            .*##:            =#%%-                                       .####*===+%%@@@@#.   ");
    puts("          +%%#            .:##%-            =%%%=                                        :*####%%##%@@@@=    ");
    puts("         .#%%*      .-=*###%%%%=            -#%#+                           .==+++-.       -+#####**%%%%:    ");
    puts("         -#%#=.:-=*#########%%%+            -#%##                          -#@%%%%##*:             +%%%%     ");
    puts("         +#%%####**+++=--::-#%%*            -#%##                         .#@@%%%%%%%#*:           *%%@#     ");
    puts("        .*%##.             .#%%*            -####                          *@%*. :+%%%##-          #%%@+     ");
    puts("        -###*              :#%%*            -####                         .#%=     .*%%##-        .%%%@-     ");
    puts("        =#%#=              -#%#+            -####                         .###       *%%#*.       -%%%@:     ");
    puts("        *#%#-              =#%#+            -####.                        .*##-      .%###:       =%%%%:     ");
    puts("        ###%:              +#%#=            -###%.                         +###:     +####.       -%%%@:     ");
    puts("       :####.              ##%#-            :###%:                         :##%+    =####-        -%@%@:     ");
    puts("       =#%##               ###%-            :###%:                          +#%%*-:+####-         =%%%%.     ");
    puts("       *#%%=               *###-            :##%%--+=:                       =#%%%%%%##-          +%%%%      ");
    puts("      -##%%.               *#%#=            .##@@%###=.        +##=           :+####*=.           *%%%#      ");
    puts("      *#%%*                ##%%+            .#%@@%#*+:        -%%%%-             ...              *%%%*      ");
    puts("      -=*#:                #%%%+          .-+%%%#+:           .+**=                               #%%%*      ");
    puts("        ..                 =#%*-        .+#*+=:..                                                 #%%%*      ");
    puts("                           :-.                                                                    #%%%*      ");
    puts("                                                                                                  #%%%#      ");
    puts("                                                                                                  *#%#%      ");
    puts("                                                                                                  +%%#%.     ");
    puts("                                                                                                  +%%#%.     ");
    puts("                                                                                                  -*%%#.     ");
    puts("                                                                                                   -=:.      ");
    printf("\n�Ы����N���~��...\n");
    getch(); // ���ϥΪ̾\Ū
    clear();
}


// �˦r���T����
void print_triangle() {
    char ch;
    while (1) {
        printf("�п�J�@�Ӧr���]a ~ n�^�G");
        scanf(" %c", &ch);

        if (ch >= 'a' && ch <= 'n') {
            clear();
            for (char i = ch; i >= 'a'; i--) {
                for (char j = i; j <= ch; j++) {
                    printf("%c", j);
                }
                printf("\n");
            }
            printf("\n�����N���^�D���...");
            getch();
            clear();
            break;
        } else {
            printf("��J���~�A�Э��s��J a ~ n ���r���C\n");
        }
    }
}

// ���k��
void print_table() {
    int n;
    while (1) {
        printf("�п�J�@�Ӿ�ơ]1 ~ 9�^�G");
        scanf("%d", &n);

        if (n >= 1 && n <= 9) {
            clear();
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    printf("%2d ", i * j);
                }
                printf("\n");
            }
            printf("\n�����N���^�D���...");
            getch();
            clear();
            break;
        } else {
            printf("��J���~�A�Э��s��J 1 ~ 9 ����ơC\n");
        }
    }
}

// �O�_�~��
void ask_continue() {
    char ans;
    while (1) {
        printf("Continue? (y/n)�G");
        scanf(" %c", &ans);

        if (ans == 'Y' || ans == 'y') {
            clear();
            break;
        } else if (ans == 'N' || ans == 'n') {
            printf("�����{���A��^�@�~�t��...\n");
            exit(0);
        } else {
            printf("��J���~�A�п�J y �� n�C\n");
        }
    }
}

int main() {
    int pw1, pw2, pw3, pw4;
    int attempts = 0;
    showBanner(); // ��ܶ}����

    // �K�X����
    do {
        printf("�п�J�|��Ʀr�K�X�G\n");
        scanf("%d %d %d %d", &pw1, &pw2, &pw3, &pw4);

        if (pw1 == 2 && pw2 == 0 && pw3 == 2 && pw4 == 5) {
            printf("��J���T\n");
            system("cls");
            break;
        } else {
            attempts++;
            printf("�K�X���~�A�Э��s��J�]�w���~ %d ���^\n", attempts);
            if (attempts == 3) {
                printf("ERROR\a\n");
                return 0;
            }
        }
    } while (1);

    // �D���
    char choice;
    while (1) {
        puts(" --------------------------");
        puts("| A. �r���ˤT����         |");
        puts("| B. ��ܭ��k�� (1~9)     |");
        puts("| C. �����{�� (y/n)       |");
        puts(" --------------------------");
        printf("Please choose an option�G\n");  
        scanf(" %c", &choice);
        clear();

        if (choice == 'A' || choice == 'a') {
            print_triangle();
        } else if (choice == 'B' || choice == 'b') {
            print_table();
        } else if (choice == 'C' || choice == 'c') {
            ask_continue();
        } else {
            printf("�ﶵ���~�A�Э��s��J�C\n");
        }
    }
    system("pause");
    return 0;
}
/*�b�o�����g C �y�����\�઺�L�{���A�ڹJ��F�X�ӹ�ھާ@�W�`�����e�����������D�C�����O�b printf() ���~�ΤF����r�e������r�� \�A�Ҧp \���A�o�|�ɭP�sĶ���~�P���D�k�� �C�o���ڷN�Ѩ�b���^��V�X��X�ɡA�����S�O�`�N \ �u��f�t�� \n�B\t ���X�k�y�k�ϥΡA�_�h�|�y���sĶ���~�C

�ĤG�Ӱ��D�N�O .exe �ɮ׵L�k���s�sĶ�A��]�O�{���|�����������C�o�O��Ǫ̱`�J�쪺���p�A�]�����ڦb�C�����槹�{����A�����T�������{�������A�γz�L�u�@�޲z���j�������A�~�ॿ�`���s�sĶ�C

�o�ǿ��~���M���j�A�����ݩ��Ȥ��D�`�`�����Ӹ`�A������|��u�g��v�M�u�]�o�ʡv���O���ơC�z�L�o���m�ߡA�ڤ��u���x�F�򥻪�����P�_�P getch()�Bsystem("cls") ���ϥΡA�]���x�����~�T�����PŪ�P�����ޥ��A���Ӧb��@�����\��ɷ|�󦳫H�߳B�z�U�ج�o���p�C*/




 
 
 
 
 
 
 
 
 
 
