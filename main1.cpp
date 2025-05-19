#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

struct processes {
    int process;
    int ram;
    bool running;
};

class Queue {
    struct node {
        int data;
        struct node *next;
    } *front = NULL, *rear = NULL;

public:
    bool isEmpty(void) {
        return (front == NULL);
    }

    void enqueue(int num) {
        node *temp = new node;
        temp->data = num;
        temp->next = NULL;
        if (front == NULL)
            front = rear = temp;
        else {
            rear->next = temp;
            rear = temp;
        }
    }

    int dequeue() {
        if (isEmpty())
            return -1;
        else {
            int data = front->data;
            node *temp = front;
            front = front->next;
            delete temp;
            return data;
        }
    }
};

class Resources {
public:
    static int sys_ram;
    static int sys_cores;
    static int sys_hard;

    Resources(int r, int c, int h) {
        sys_cores = c;
        sys_ram = r;
        sys_hard = h;
    }
};

int Resources::sys_cores = 0;
int Resources::sys_ram = 0;
int Resources::sys_hard = 0;

void console_OS_intro() {
    cout << "\t\tLoading Operating System..." << endl;
    sleep(3);
    system("clear");
    cout << "\t\t=----------------------------=" << endl;
    cout << "\t\t=-----Operating System-------=" << endl;
    cout << "\t\t=----------------------------=" << endl;
    cout << "\t\t=------- Javaline 79 --------=" << endl;
    cout << "\t\t=----------------------------=" << endl;

    cout << "\n\t\tLoading";
    for (int i = 0; i < 10; ++i) {
        cout << ".";
        cout.flush();
        usleep(200000);
    }
    cout << endl;
}

void console_OS_menu() {
system("clear");
    cout << "\n\t\tLoading Main menu";
    for (int i = 0; i < 10; ++i) {
        cout << ".";
        cout.flush();
        usleep(200000);
    }
    cout << "Memory left : " << Resources::sys_ram << endl;
    cout << "\t\t=----------------------------=" << endl;
    cout << "\t\t=----- Menu Javaline  -------=" << endl;
    cout << "\t\t=----------------------------=" << endl;
    cout << "\t\tPress 1: Play Tik Tak Game " << endl;
    cout << "\t\tPress 2: Create new File " << endl;
    cout << "\t\tPress 3: Calculator " << endl;
    cout << "\t\tPress 4: Time & Clock " << endl;
    cout << "\t\tPress 5: Copy File to Another " << endl;
    cout << "\t\tPress 6: Delete a File " << endl;
    cout << "\t\tPress 7: File Information " << endl;
    cout << "\t\tPress 8: View Calendar " << endl;
    cout << "\t\tPress 0: Shutdown OS" << endl;
    cout << "\t\t------------------------------" << endl;
    cout << "\t\tEnter your respective no.:> ";
}

void exec_game_tiktak() {
    cout << "\t\tLoading..." << endl;
    sleep(2);
    system("clear");
    string str = "g++ game_tiktak.cpp";
    system(str.c_str());
    string c = "gnome-terminal -- sh -c '""./a.out; exec bash""'";
    system(c.c_str());
}

void sys_resources() {

    int num_c, num_r;
    int hdd;

    cout << "\t\t=----Javaline Resources-----=" << endl;
    cout << "\t\t=----    Allocation    -----=" << endl;
    cout << "\t\t=---------------------------=" << endl;

    while (1) {
        cout << "\t\t= Num Cores(1~4):> ";
        cin >> num_c;
        if (num_c >= 1 && num_c <= 4) {
            Resources::sys_cores = num_c;
            break;
        }
    }

    while (1) {
        cout << "\t\t= Sys RAM(Mbs):> ";
        cin >> num_r;
        if (num_r >= 1 && num_r <= 10000) {
            Resources::sys_ram = num_r;
            break;
        }
    }

    while (1) {
        cout << "\t\t= Sys HDD(Mbs):> ";
        cin >> hdd;
        if (hdd >= 1000 && hdd <= 100000) {
            Resources::sys_hard = hdd;
            break;
        }
    }
}

void* sys_createNewFile(void *args) {
    cout << "\t\tLoading Creating File..." << endl;
    sleep(2);
    system("clear");
    int fd;
    char filename[255];
    string c = "gnome-terminal -- sh -c '""./a.out; exec bash""'";
    system(c.c_str());
    cout << "Enter the filename: ";
    cin >> filename;
    fd = creat(filename, O_RDWR | O_CREAT);
    if (fd != -1) {
        cout << "Your file -> " << filename << " has been created " << endl;
    } else {
        cout << "An Error Occurred Processing your request " << endl;
    }

    pthread_exit(NULL);
}

void exec_calculator() {
    cout << "\t\tLoading Calculator" << endl;
    sleep(2);
    system("clear");
    string str = "g++ calculator.cpp";
    system(str.c_str());
    string c = "gnome-terminal -- sh -c '""./a.out; exec bash""'";
    system(c.c_str());
}

void exec_time() {
    cout << "\t\tLoading..." << endl;
    sleep(2);
    system("clear");
    string str = "g++ time.cpp";
    system(str.c_str());
    string c = "gnome-terminal -- sh -c '""./a.out; exec bash""'";
    system(c.c_str());
}

void exec_copyFile() {
    cout << "\t\tCopying Data..." << endl;
    sleep(2);
    system("clear");
    string str = "g++ FE_copyfile.cpp";
    system(str.c_str());
    string c = "gnome-terminal -- sh -c '""./a.out; exec bash""'";
    system(c.c_str());
}

void * sys_deleteFile(void *args) {
    cout << "\n\n\t\t=---------<< File Explorer >>---------=" << endl;
    string filename;
    cout << "\t\tEnter the file name to be deleted: ";
    cin >> filename;
    cout << "\t\tDeleting Data..." << endl;
    sleep(2);
    system("clear");
    if (remove(filename.c_str()) == 0)
        printf("Deleted successfully");
    else
        printf("Unable to delete the file");

    pthread_exit(NULL);
}

void sys_fileinfo() {
    cout << "\t\tLoading File Information..." << endl;
    sleep(2);
    system("clear");
    string str = "g++ FE_fileinfo.cpp";
    system(str.c_str());
    string c = "gnome-terminal -- sh -c '""./a.out; exec bash""'";
    system(c.c_str());
}

void exec_calender() {
    string str = "g++ calender.cpp";
    system(str.c_str());
    string c = "gnome-terminal -- sh -c '""./a.out; exec bash""'";
    system(c.c_str());
}

void assignRam(processes allProcess[]) {
    allProcess[0].ram = 100;
    allProcess[1].ram = 100;
    allProcess[2].ram = 200;
    allProcess[3].ram = 30;
    allProcess[4].ram = 100;
    allProcess[5].ram = 100;
    allProcess[6].ram = 50;
    allProcess[7].ram = 200;
    allProcess[8].ram = 500;
    allProcess[9].ram = 300;
}

int main(void) {
    Queue readyQueue;
    processes allProcess[10];
    assignRam(allProcess);
    console_OS_intro();
    sys_resources(); // allocates Resources to the OS Simulator

    bool stp_ctrl = false;

    while (!stp_ctrl) {
        system("clear");

        int choice;
        console_OS_menu();
        cin >> choice;

        int task_ram = 0; // Variable to store RAM requirements of selected task

        if (choice >= 0 && choice <= 8) {
            // Determine RAM requirement of selected task
            task_ram = allProcess[choice].ram;
        }

        switch (choice) {
            case 1:
                if (Resources::sys_ram > task_ram) {
                    // If enough memory available, execute the task
                    // Subtract task's RAM requirement from available memory
                    Resources::sys_ram -= task_ram;
                    // Execute the task
                    exec_game_tiktak();
                    Resources::sys_ram += task_ram;
                } else {
                    // If not enough memory available, enqueue the task
                    readyQueue.enqueue(choice);
                }
                break;
            case 2:
                if (Resources::sys_ram > task_ram) {
                    // If enough memory available, execute the task
                    // Subtract task's RAM requirement from available memory
                    Resources::sys_ram -= task_ram;
                    // Execute the task
                    pthread_t newFileThread;
                    pthread_create(&newFileThread, NULL, &sys_createNewFile, NULL);
                    pthread_join(newFileThread, NULL);
                    Resources::sys_ram += task_ram;
                } else {
                    // If not enough memory available, enqueue the task
                    readyQueue.enqueue(choice);
                }
                break;
            case 3:
                if (Resources::sys_ram > task_ram) {
                    // If enough memory available, execute the task
                    // Subtract task's RAM requirement from available memory
                    Resources::sys_ram -= task_ram;
                    // Execute the task
                    exec_calculator();
                    Resources::sys_ram += task_ram;
                } else {
                    // If not enough memory available, enqueue the task
                    readyQueue.enqueue(choice);
                }
                break;
            case 4:
                if (Resources::sys_ram > task_ram) {
                    // If enough memory available, execute the task
                    // Subtract task's RAM requirement from available memory
                    Resources::sys_ram -= task_ram;
                    // Execute the task
                    exec_time();
                    Resources::sys_ram += task_ram;
                } else {
                    // If not enough memory available, enqueue the task
                    readyQueue.enqueue(choice);
                }
                break;
            case 5:
                if (Resources::sys_ram > task_ram) {
                    // If enough memory available, execute the task
                    // Subtract task's RAM requirement from available memory
                    Resources::sys_ram -= task_ram;
                    // Execute the task
                    exec_copyFile();
                    Resources::sys_ram += task_ram;
                } else {
                    // If not enough memory available, enqueue the task
                    readyQueue.enqueue(choice);
                }
                break;
            case 6:
                if (Resources::sys_ram > task_ram) {
                    // If enough memory available, execute the task
                    // Subtract task's RAM requirement from available memory
                    Resources::sys_ram -= task_ram;
                    // Execute the task
                    pthread_t sys_delfiles;
                    pthread_create(&sys_delfiles, NULL, &sys_deleteFile, NULL);
                    pthread_join(sys_delfiles, NULL);
                    Resources::sys_ram += task_ram;
                } else {
                    // If not enough memory available, enqueue the task
                    readyQueue.enqueue(choice);
                }
                break;
            case 7:
                if (Resources::sys_ram > task_ram) {
                    // If enough memory available, execute the task
                    // Subtract task's RAM requirement from available memory
                    Resources::sys_ram -= task_ram;
                    // Execute the task
                    sys_fileinfo();
                    Resources::sys_ram += task_ram;
                } else {
                    // If not enough memory available, enqueue the task
                    readyQueue.enqueue(choice);
                }
                break;
            case 8:
                if (Resources::sys_ram > task_ram) {
                    // If enough memory available, execute the task
                    // Subtract task's RAM requirement from available memory
                    Resources::sys_ram -= task_ram;
                    // Execute the task
                    exec_calender();
                    Resources::sys_ram += task_ram;
                } else {
                    // If not enough memory available, enqueue the task
                    readyQueue.enqueue(choice);
                }
                break;
            case 0:
                stp_ctrl = true;
                break;
            default:
                cout << "Invalid input. Please try again." << endl;
                sleep(1);
                break;
        }

        // Check if any tasks can be executed from the ready queue
        while (!readyQueue.isEmpty() && Resources::sys_ram > allProcess[readyQueue.dequeue()].ram) {
            // If enough memory available, execute the task
            int dequeued_task = readyQueue.dequeue();
            Resources::sys_ram -= allProcess[dequeued_task].ram;
            // Execute the task
            switch (dequeued_task) {
                case 1:
                    exec_game_tiktak();
                    break;
                case 2:
                    pthread_t newFileThread;
                    pthread_create(&newFileThread, NULL, &sys_createNewFile, NULL);
                    pthread_join(newFileThread, NULL);
                    break;
                case 3:
                    exec_calculator();
                    break;
                case 4:
                    exec_time();
                    break;
                case 5:
                    exec_copyFile();
                    break;
                case 6:
                    pthread_t sys_delfiles;
                    pthread_create(&sys_delfiles, NULL, &sys_deleteFile, NULL);
                    pthread_join(sys_delfiles, NULL);
                    break;
                case 7:
                    sys_fileinfo();
                    break;
                case 8:
                    exec_calender();
                    break;
            }
        }
    }

    return 0;
}

	

