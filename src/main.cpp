#include "LinkedList.h"

void showMenu() {
    cout << "\n========== 单链表操作菜单 ==========" << endl;
    cout << "1. 有序插入元素" << endl;
    cout << "2. 删除元素" << endl;
    cout << "3. 查找元素" << endl;
    cout << "4. 输出所有元素" << endl;
    cout << "5. 获取链表长度" << endl;
    cout << "0. 退出程序" << endl;
    cout << "====================================" << endl;
    cout << "请选择: ";
}

int main() {
    Node* list = initList();
    int choice, value, pos;

    cout << "=== 带头结点单链表程序启动 ===" << endl;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "请输入要插入的整数: ";
                cin >> value;
                insertOrdered(list, value);
                break;
            case 2:
                cout << "请输入要删除的整数: ";
                cin >> value;
                deleteNode(list, value);
                break;
            case 3:
                cout << "请输入要查找的整数: ";
                cin >> value;
                if (searchNode(list, value, pos)) {
                    cout << "找到 " << value << "，位置为: " << pos << endl;
                } else {
                    cout << "未找到 " << value << endl;
                }
                break;
            case 4:
                displayList(list);
                break;
            case 5:
                cout << "当前链表长度: " << getLength(list) << endl;
                break;
            case 0:
                cout << "正在退出..." << endl;
                break;
            default:
                cout << "无效输入，请重新选择 (0-5)" << endl;
                break;
        }
    } while (choice != 0);

    destroyList(list);
    return 0;
}