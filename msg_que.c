#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Minimal required structure
struct message {
    long type;         // Must be of type long
    char text[100];    // Message content
};

int main() {
    key_t key;
    int msgid;
    struct message msg;

    // Generate a unique key using an existing file
    key = ftok("file", 65);

    // Create a message queue with read/write permission
    msgid = msgget(key, 0666 | IPC_CREAT);

    // ----- Send a Message -----
    msg.type = 1; // Message type must be > 0
    printf("Enter a message: ");
    fgets(msg.text, sizeof(msg.text), stdin);
    msg.text[strcspn(msg.text, "\n")] = '\0'; // Remove newline

    msgsnd(msgid, &msg, sizeof(msg.text), 0);
    printf("Message sent: %s\n", msg.text);

    // ----- Receive the Message -----
    msgrcv(msgid, &msg, sizeof(msg.text), 1, 0);
    printf("Message received: %s\n", msg.text);

    // ----- Remove the Message Queue -----
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}

