#include <libintl.h>
#include <locale.h>
#include <stdio.h>

#define _(String) gettext(String)
#define _t(String1, String2,n) ngettext(String1, String2, n)

int main(int argc, const char *argv[])
{
    int i;
    setlocale(LC_ALL, "");
    bindtextdomain("helloworldintl", "/usr/share/locale");
    textdomain("helloworldintl");
    printf(_("again"));
    printf("\n");
    printf(_("Hello World"));
    printf("\n");
    printf(_("These text demonstrate that translation using po files is easier\n"));
    scanf("%d",&i);
    printf(_t("This number %d is of singular form","This number %d is of plural form",i),i);
    printf("\n");
    printf(_("The magic number is %d\n"),i);
    printf(_("These are additional words"));
    printf("\n");
    printf(_("I love translation\n"));
    return 0;
}
