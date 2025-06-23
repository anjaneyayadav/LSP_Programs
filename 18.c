#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
int main()
{
    const char *filename = "file.txt";
    const char *username = "user1";
    // Get user info from username
    struct passwd *pwd = getpwnam(username);
    if (pwd == NULL)
    {
        printf("User %s not found.\n", username);
        return 1;
    }
    uid_t uid = pwd->pw_uid;
    gid_t gid = pwd->pw_gid;
    // Change ownership of the file
    if (chown(filename, uid, gid) == 0)
    {
        printf("Ownership of %s changed to user %s\n", filename, username);
    }
    else
    {
        perror("Failed to change ownership");
        return 1;
    }
    return 0;
} // explain each step  by step each
