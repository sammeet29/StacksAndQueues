#include "CppUTest/CommandLineTestRunner.h"

int main(int arg_count, char ** args)
{
    return CommandLineTestRunner::RunAllTests(arg_count,args);
}
