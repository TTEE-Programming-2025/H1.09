#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD "2025"
#define MAX_ATTEMPTS 3
#define MAX_STUDENTS 10

typedef struct {
    char name[50];
    char id[10];
    int math;
    int physics;
    int english;
    float average;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

// �ۭq�禡�G�r��۵�����A���ϥ� strcmp
int myStrEqual(char *a, char *b) {
    int i = 0;
    while (a[i] != '\0' || b[i] != '\0') {
        if (a[i] != b[i]) return 0;
        i++;
    }
    return 1;
}

// �ӤH�����w��e��
void showWelcomeScreen() {
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
    puts("                                                                                                  #%%%*      ");
    puts("                                                                                                  #%%%#      ");
    puts("                                                                                                  *#%#%      ");
    puts("                                                                                                  +%%#%.     ");
    puts("                                                                                                  +%%#%.     ");
    puts("                                                                                                  -*%%#.     ");
    puts("                                                                                                   -=:.      ");
}

// �\�� 1�G�K�X�n�J
int login() {
    char input[10];
    int attempt = 0;

    while (attempt < MAX_ATTEMPTS) {
        printf("�п�J 4 ��ƱK�X�G");
        scanf("%s", input);
        if (myStrEqual(input, PASSWORD)) {
            printf("�n�J���\�A�w��ϥΪ̡I\n");
            return 1;
        } else {
            printf("�K�X���~�A�Ѿl���ơG%d\n", MAX_ATTEMPTS - attempt - 1);
        }
        attempt++;
    }

    printf("���~���ƹL�h�A�t�ε����C\n");
    return 0;
}

// �\�� 2�G�D���
void showMenu() {
    system("cls"); // Windows �ΡA�Y�O Linux �Ч令 "clear"
    printf("------------[Grade System]----------\n");
    printf("| a. Enter student grades          |\n");
    printf("| b. Display student grades        |\n");
    printf("| c. Search for student grades     |\n");
    printf("| d. Grade ranking                 |\n");
    printf("| e. Exit system                   |\n");
    printf("------------------------------------\n");
}

// �\�� 3�G��J�ǥͦ��Z
void enterGrades() {
    printf("�п�J�ǥͤH�� (5~10)�G");
    scanf("%d", &studentCount);
    if (studentCount < 5 || studentCount > 10) {
        printf("�H�ƿ��~�A�Э��s��J�C\n");
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        printf("\n�� %d ��ǥ͸�ơG\n", i + 1);
        printf("�m�W�G");
        scanf("%s", students[i].name);
        printf("�Ǹ��]6�X�^�G");
        scanf("%s", students[i].id);
        printf("�ƾǦ��Z�G");
        scanf("%d", &students[i].math);
        printf("���z���Z�G");
        scanf("%d", &students[i].physics);
        printf("�^�妨�Z�G");
        scanf("%d", &students[i].english);

        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0f;
    }
}

// �\�� 4�G��ܩҦ����Z
void displayGrades() {
    printf("\n%-10s %-10s %-6s %-6s %-6s %-6s\n", "�m�W", "�Ǹ�", "�ƾ�", "���z", "�^��", "����");
    for (int i = 0; i < studentCount; i++) {
        printf("%-10s %-10s %-6d %-6d %-6d %-6.1f\n",
               students[i].name, students[i].id, students[i].math,
               students[i].physics, students[i].english, students[i].average);
    }
}

// �\�� 5�G�d�߯S�w�ǥ�
void searchGrades() {
    char searchName[50];
    printf("�п�J�n�d�ߪ��ǥͩm�W�G");
    scanf("%s", searchName);

    for (int i = 0; i < studentCount; i++) {
        if (myStrEqual(students[i].name, searchName)) {
            printf("%s �����Z�p�U�G\n", students[i].name);
            printf("�ƾǡG%d  ���z�G%d  �^��G%d  �����G%.1f\n",
                   students[i].math, students[i].physics, students[i].english, students[i].average);
            return;
        }
    }
    printf("�d�L���ǥ͡C\n");
}

// �\�� 6�G�������Z�Ƨ�
void gradeRanking() {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            if (students[j].average < students[j + 1].average) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("���Z�Ѱ��ܧC�ƧǦp�U�G\n");
    displayGrades();
}

// �D�{��
int main() {

    if (!login()) return 0;

    char choice;
    while (1) {
        showMenu();
        printf("�п�ܥ\�� (a-e)�G");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a': enterGrades(); break;
            case 'b': displayGrades(); break;
            case 'c': searchGrades(); break;
            case 'd': gradeRanking(); break;
            case 'e': {
                char confirm;
                printf("�T�w�n���}�ܡH(y/n)�G");
                scanf(" %c", &confirm);
                if (confirm == 'y' || confirm == 'Y') {
                    printf("�t�ε����A�P�¨ϥΡI\n");
                    return 0;
                }
                break;
            }
            default: printf("��J���~�A�Э��s��ܡC\n"); break;
        }

        printf("�� Enter ���~��...\n");
        getchar(); getchar(); // ���ݿ�J
    }

    return 0;
}
//�Q�׻P�߱o�G 
/*�o���ڧ����F�@��²�����Z�t�ΡA���I�b��m�߸�ƿ�J�B�B�z�B�d�߻P�Ƨǵ����޿�A�ïS�O�D�ԧ������ϥ� strcmp() �Ӥ��r��C��ӹL�{���ڧ�`�J�z�ѤF C �y���b�u�r���}�C�v�W�����h�B�@�C

�ڦۤv�g�F�@�Ө禡 myStrEqual() �Ӱ��r��v�r���A�o���ھǷ|����̿�禡�w�A�n�ۤv�B�z�r���B\0 �����M�C�@�Ӧr��������A�o�زӸ`���`�Τ��ب禡�ɫܮe�������C�o�]���ڧ󦳦��N�P�A�]���گu���F�ѤF�{���̬O���u���D�v��Ӧr��@���@�˪��C

���F�r�����A��ӱM�������ڽm�ߤF�G

struct �ΨӦs�ǥ͸�ơ]�m�W�B�Ǹ��B���Z�^

array ���x�s�h�����

�Q�ΰj��p�⥭�����Z

�ή�w�Ƨǧ�ǥͫ��������ƱƧ�

�Q�� switch �M while �غc�@�ӿ��t��

���ٳ]�p�F�ۤv�� ASCII �Ϯװ����n�J�e���A����ӵ{�����F�\�৹��A�]�h�F�@�I�ӤH�S��C

�o���{���\�����M�������A�����[�\�F C �y���֤ߪ��U�ذ򥻾ާ@�A���O�}�C�B�z�B����P�_�B�禡�ϥΡB��ƿ�J��X���C�󭫭n���O�A�o���ڨS���̿� strcmp()�A�o���ڹ侀�h�޿観��Ϲꪺ�z�ѡA�o�I��\�ॻ���٦��N�q�C

�`���ӻ��A�o���M�D���ڽm��ܦh C �y�����򥻥\�A�]�D�ԤF�侀�h�B�@���x���C�ڷ|��o�ӵ{���d�U�ӡA������i���t�Ϊ���¦�C */ 
