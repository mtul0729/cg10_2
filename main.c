#include <stdio.h>

struct char_con {
    char c;
    unsigned times;
};
typedef struct char_con char_con;

int main() {
    char x;
    int i;
    char_con charCon[200];
    unsigned count = 0;
    //输入字符
    scanf("%c", &x);
    while (x != 10 && x != 13) {
        for (i = 0; i < count; ++i) {
            if (x == charCon[i].c) {
                charCon[i].times++;
                break;
            }
        }
        if (i == count) {
            charCon[i].c = x;
            charCon[i].times = 1;
            count++;
        }
        scanf("%c", &x);
    }
    //通过指针排序
    char_con *p[count];
    for (i = 0; i < count; ++i) {//用指针指向它们
        p[i] = charCon + i;
    }
    //冒泡排序
    for (i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (p[j]->times < p[j + 1]->times) {
                char_con *t;
                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }
    }
    for (i = 0; i < count - 1; ++i) {
        printf("%c-%u", p[i]->c, p[i]->times);
        if ((i + 1) % 4 == 0)printf("\n");
        else printf(" ");
    }
    printf("%c-%u", p[i]->c, p[i]->times);//最后一行行末只换行
    printf("\n");
    return 0;
}
