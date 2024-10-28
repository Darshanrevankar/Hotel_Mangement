#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
struct node
{
    int room_number, member;
    char name[25], start_time[25], End_time[25], from[25], to[25];
    long int phone_number;
    struct node *link;
};
typedef struct node *NODE;
NODE first = NULL, num;
int n = 20, i = 0, count = 0, val = 0;

NODE registration()
{
    char name[25], start_time[25], End_time[25], from[25], to[25];
    int room_number, member;
    long int phone_number;
    cout << "\nEnter the Room Number: ";
    cin >> room_number;
    if (room_number > 400)
    {
        cout << "\n\nEnter Room number less than 400\n\n";
        return 0;
    }
    if (first != NULL)
    {
        num = first;
        while (num != NULL)
        {
            if (num->room_number == room_number)
            {
                cout << "\n\nRoom is already Booked\n\n";
                cout << "\nEnter the Room Number: ";
                cin >> room_number;
                break;
            }
            num = num->link;
        }
    }
    cout << "\nEnter the Host Name: ";
    cin >> name;
    cout << "\nEnter the Number of member: ";
    cin >> member;
    cout << "\nEnter the Start Time: ";
    cin >> start_time;
    cout << "\nEnter the End Time: ";
    cin >> End_time;
    cout << "\nFrom: ";
    cin >> from;
    cout << "\nTo: ";
    cin >> to;
    cout << "\n\n";

    NODE room_registration, ptr;
    room_registration = (NODE)malloc(sizeof(struct node));
    if (room_registration == NULL)
    {
        cout << "Memory not available ";
        exit(0);
    }
    if (first == NULL)
    {
        val = room_number;
    }
    room_registration->link = NULL;
    room_registration->room_number = room_number;
    room_registration->member = member;
    strcpy(room_registration->name, name);
    strcpy(room_registration->start_time, start_time);
    strcpy(room_registration->End_time, End_time);
    strcpy(room_registration->from, from);
    strcpy(room_registration->to, to);
    count++;

    ptr = first;
    return room_registration;
}

NODE insertAtFront()
{
    NODE temp, cur, cur2;
    temp = registration();
    if (first == NULL)
    {
        return temp;
    }
    else
    {
        cur = first;
        if (temp->room_number > val)
        {
            if (first->link == NULL)
            {
                cur->link = temp;
                return first;
            }
            while (temp->room_number > cur->room_number && cur->link != NULL)
            {
                cur2 = cur;
                cur = cur->link;
            }
            if (cur->room_number < temp->room_number)
            {
                cur->link = temp;
                return first;
            }
            else
            {
                temp->link = cur;
                cur2->link = temp;
                return first;
            }
        }
        else if (temp->room_number < val)
        {
            if (temp->room_number < cur->room_number)
            {
                temp->link = first;
                return temp;
            }
            else
            {
                while (temp->room_number > cur->room_number)
                {
                    cur2 = cur;
                    cur = cur->link;
                }
                temp->link = cur;
                cur2->link = temp;
                return first;
            }
        }
    }
}

void Room_Details()
{
    NODE cur;
    cur = first;
    if (cur == NULL)
    {
        cout << "All room are empty\n";
    }
    else
    {
        cout << "\t\t\t\t*********Details*********\n\n\n";
        cout << "Room Number\t"
             << "Host Name\t"
             << "Total Members\t"
             << "Start Time\t"
             << "End Time\t"
             << "From\t\t"
             << "To";
        cout << "\n";
    }
    while (cur != NULL)
    {
        cout << cur->room_number << "\t\t" << cur->name << "\t\t" << cur->member << "\t\t" << cur->start_time << "\t\t" << cur->End_time << "\t\t" << cur->from << "\t\t" << cur->to;
        cout << "\n";
        cur = cur->link;
    }
    cout << "\n\n";
}

NODE delete_registration()
{
    int value;
    cout << "Enter the Room Number: ";
    cin >> value;
    NODE cur, prev, ptr2;
    cur = first;
    if (first == NULL)
    {
        cout << "Cancelled the Booking of Room Number" << first->room_number;
        return NULL;
    }
    else if (cur->room_number == value)
    {
        ptr2 = first;
        first = ptr2->link;
        free(ptr2);
        count--;
        return first;
    }
    else
    {
        prev = NULL;
        cur = first;
        while (cur->room_number != value)
        {
            prev = cur;
            cur = cur->link;
        }
        if (cur->link == NULL)
        {
            cout << "Cancelled the Booking of Room Number " << cur->room_number << "\n\n";
            free(cur);
            prev->link = NULL;
            count--;
            return first;
        }
        else
        {
            cout << "Cancelled the Booking of Room Number " << cur->room_number << "\n\n";
            prev->link = cur->link;
            cur->link = NULL;
            free(cur);
            count--;
            return first;
        }
    }
}

void Details()
{
    NODE cur;
    int rn;
    cur = first;
    cout << "Enter the room number: ";
    cin >> rn;
    if (cur == NULL)
    {
        cout << "All room are empty\n";
    }
    while (cur != NULL)
    {
        if (cur->room_number == rn)
        {
            cout << "\n\n\t\t\t\t*********Details*********\n\n";
            cout << "\nRoom Number: " << cur->room_number;
            cout << "\n\nHost Name: " << cur->name;
            cout << "\n\nTotal Members: " << cur->member;
            cout << "\n\nStart Time: " << cur->start_time;
            cout << "\n\nEnd Time: " << cur->End_time;
            cout << "\n\nFrom: " << cur->from;
            cout << "\n\nTo: " << cur->to << endl;
            cout << "\n";
        }
        cur = cur->link;
    }
}

void Room()
{
    NODE cur;
    cur = first;
    if (cur == NULL)
    {
        cout << "All room are empty\n";
    }
    else
    {
        cout << "\n\n"
             << (400 - count) << " empty rooms are Available\n\n";
    }
}

int main()
{
    int ch, k;
    cout << "\n\n\n\t\t\t**********************    WELCOME TO THE BRINDAVAN LODGE    **********************"
         << "\n\n";
    while (1)
    {
        cout << "Enter the choice" << endl;
        cout << "1.Registration of Room\n"
             << "2.Reservation\n"
             << "3.Details\n"
             << "4.Room Available\n"
             << "5.Check Out\n"
             << "6.Host Information\n"
             << "7.Exit\n";

        cout<<"Enter your choice: ";
        cin >> ch;
        cout << "\n";
        switch (ch)
        {
        case 1:
            first = insertAtFront();
            break;
        case 2:
            first = insertAtFront();
            cout << "\t\t\tReservation is Done\n\n";
            break;
        case 3:
            Room_Details();
            break;
        case 4:
            Room();
            break;
        case 5:
            first = delete_registration();
            break;
        case 6:
            Details();
            break;
        case 7:
            exit(0);
        }
    }
    return 0;
}