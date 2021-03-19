#include <iostream>
#include <string_view>

using namespace std;

static string_view<char> self_path{""};

int main(int argc, char **argv)
{
    self_path = argv[0];
    return 0;
}