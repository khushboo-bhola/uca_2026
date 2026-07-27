#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

void displayInfo(struct stat info)
{
    printf("\n========== FILE INFORMATION ==========\n");

    if (S_ISREG(info.st_mode))
        printf("Type            : Regular File\n");
    else if (S_ISDIR(info.st_mode))
        printf("Type            : Directory\n");
    else
        printf("Type            : Other\n");

    printf("Permissions     : %o\n", info.st_mode & 0777);
    printf("Size            : %ld Bytes\n", info.st_size);
    printf("Link Count      : %ld\n", info.st_nlink);
    printf("User ID         : %d\n", info.st_uid);
    printf("Group ID        : %d\n", info.st_gid);

    printf("Access Time     : %s", ctime(&info.st_atime));
    printf("Modified Time   : %s", ctime(&info.st_mtime));
    printf("Changed Time    : %s", ctime(&info.st_ctime));
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    struct stat fileInfo;

    if (stat(argv[1], &fileInfo) != 0)
    {
        printf("Unable to access %s\n", argv[1]);
        return 1;
    }

    printf("Path : %s\n", argv[1]);

    displayInfo(fileInfo);

    return 0;
}