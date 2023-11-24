#include <stdio.h>
#include <string.h>

void putpenis(char *str)
{
    fprintf(stderr, "\r%s", str);
    usleep(rand()%60000+30000);
    return;
}
int main(int argc, char **argv)
{
   printf("++++ SCOTTISH MODE ++++\n");
   printf("watch %s's ass get owned by %s!!\n",(argc>1)?argv[1]:"matt",
          (argc>2)?argv[2]:"houst0n");

  while(1)
  {
    putpenis("8=====D  (_O_)");
    putpenis(" 8=====D (_O_)");
    putpenis("  8=====D(_O_)");
    putpenis("   8=====D_O_)");
    putpenis("    8=====DO_)");
    putpenis("     8=====D_)");
    putpenis("      8=====_)");
    putpenis("       8====_)");
    putpenis("        8===_)");
    putpenis("         8==_)");
    putpenis("       8====_)");
    putpenis("      8=====_)");
    putpenis("     8=====D_)");
    putpenis("    8=====DO_)");
    putpenis("   8=====D_O_)");
    putpenis("  8=====D(_O_)");
    putpenis(" 8=====D (_O_)");
    putpenis("8=====D  (_O_)");
  }
  return 0;
}