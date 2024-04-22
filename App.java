//Tien hanh them thu vien chuan cua Java
import java.util.Scanner; 

class Main {
    //Tao doi tuong Node
    static class Node {
        //Ham khao toi Node
        //Thuc thi ngay sau khi khai bao trong ham main
        int data;
        Node prev = null; //prev giữ vai trò liên kết Node hiện tại với Node liền trước nó
        Node next = null; //next giữ vai trò liên kết Node hiện tại với Node liền sau nó

        //Ham gan gia tri cho data cua Node
        void input(int data) { 
            this.data = data;
        }
    }

    //Menu chuc nang
    static void menu() {
        System.out.println("\n======================");
        System.out.println("0. Thoat Menu!");
        System.out.println("1. Them phan tu vao DSLK");
        System.out.println("2. Xoa phan tu trong DSLK");
        System.out.println("3. Xuat DSLK");
        System.out.println("4. Sap xep DSLK"); 
        System.out.println("5. Tim kiem vi tri cua phan tu trong DSLK");
    }

    static void menu1() {
        System.out.println("\n==========(1)==========");
        System.out.println("0. Thoat!");
        System.out.println("1. Them phan tu vao Dau DSLK");
        System.out.println("2. Them phan tu vao giua DSLK");
        System.out.println("3. Them phan tu vao Cuoi DSLK");
    }

    static void menu2(){
        System.out.println("\n==========(2)==========");
        System.out.println("0. Thoat!");
        System.out.println("1. Xoa phan tu dau");
        System.out.println("2. Xoa phan tu cuoi");
        System.out.println("3. Xoa phan tu x ");
    }
    static void menu4(){
        System.out.println("\n==========(4)==========");
        System.out.println("0. Thoat!");
        System.out.println("1. Sap xep tang dan");
        System.out.println("2. Sap xep giam dan");
    }

    //Them vao cuoi DSLK
    static Node addNode(Node head, int x) {
        Node newNode = new Node(); //Tạo đối tượng newNode của lớp Node
        newNode.input(x);   //Gọi hàm gán giá trị X cho data của newNode
        if (head == null) { //Nếu head đang rỗng thì gán gán newNode cho head
            head = newNode;
            return head;    //Trả về Node head
        }
        Node temp = head;   //Tạo đối tượng temp của lớp Node
        while (temp.next != null) { //Vòng lặp thực hiện chức năng đưa temp đến cuối Node của DSLK
            temp = temp.next;
        }
        temp.next = newNode; //Gán Node newNode cho phần next của temp
        newNode.prev = temp; //Gán Node temp cho phần prev của newNode
        return head;    //Trả về Node head
    }

    //Them vao dau DSLK
    static Node frontadd(Node head, int x) {
        Node newNode = new Node(); //Tạo đối tượng newNode của lớp Node
        newNode.input(x);   //Gọi hàm gán giá trị X cho data của newNode
        if (head == null) { //Nếu head đang rỗng thì gán gán newNode cho head
            head = newNode;
            return head;    //Trả về Node head
        }
        //head khác null thì thực hiện
        head.prev = newNode; //Gán newNode cho phần prev của head
        newNode.next = head; //Gán head cho phần next newNode
        head = newNode; //Gán newNode cho head
        return head;   //Trả về Node head
    }

    //Chieu dai List
    static int Size(Node head) {
        int count = 0; //Tạo biến nguyên count với giá trị được gán bằng 0
        while (head != null) { //Vòng lặp được thực hiện khi head khác rỗng
            count++; // Nếu vòng lặp còn chạy thì tăng count lên 1 đơn vị
            head = head.next; //Đưa head đến Node tiếp theo trong DSLK
        }
        return count; //Trả về count 
    }

    //Them vao giua DSLK
    static Node addtoIndex(Node head, int value, int index){ //index là vị trí cần thêm và value là giá trị để thêm
        if ( index == 1){ //Nếu index ở vị trí đầu tiên của DSLK
            return frontadd(head, value); //Trả về Node khi gọi hàm frontadd();
        }
        else{ //Nếu index khác 1
            //Tim vi tri can them 
            Node newNode = new Node(); //Tạo đối tượng newNode của lớp Node
            newNode.input(value); //Gọi hàm gán giá trị X cho data của newNode
            Node tmp = head; //Tạo đối tượng tmp của lớp Node và gán head cho nó
            int count = 1; //Tạo biến count kiểu dữ liệu số nguyên và gán 1 cho nó
            while( tmp != null){ //Vòng lặp được thực hiện khi tmp khác rỗng
                count++; //Vòng lặp còn thực hiện thì tăng biến count lên 1 đơn vị
                if(count == index){ //Nếu như count trùng với vị trí cần thêm
                    //Them node vào vị trí temp
                    newNode.next = tmp.next; 
                    tmp.next = newNode;
                    newNode.prev = tmp;
                    newNode.next.prev = newNode;
                    break;
                }
                tmp = tmp.next; //Đưa tmp đến Node tiếp theo trong DSLK
            }
            return head; //Trả về Node head
        }
        }        
    //Xuat toan bo Node trong DSLK
    static void export(Node head) {
        if (head == null) { //Nếu head rỗng
            System.out.println("Empty!");
            return;
        }
        Node temp = head; //Tạo đối tượng temp của lớp Node và gán head cho nó
        while (temp != null) { //Vòng lặp thực hiện khi temp khác rỗng
            System.out.print(temp.data + "->"); //In ra data của temp khi vòng lặp còn hoạt động
            temp = temp.next; //Đưa temp đến Node tiếp theo
        }
    }
    
    //Xoa Node dau
    static Node front_dele(Node head) {
        if ( head == null) { //Nếu head là rỗng
            return null; //Trả về rỗng
        }
        //Nếu head khác rỗng
        head = head.next; //Đưa head tới Node tiếp theo
        head.prev = null; //Gán null cho prev của head 
        return head; //Trả về head
    }

    //Xoa Node cuoi
    static Node lastest_dele(Node head) {
        if ( head == null) { //Nếu head là rỗng
            return null; //Trả về rỗng
        }
        Node temp = head; //Tạo đối tượng temp của lớp Node và gán head cho nó
        while (temp.next.next != null) { //Vòng lặp được thực hiện khi temp không phải là phần tử kề cuối của DSLK
            temp = temp.next; //Đưa temp đến Node tiếp theo
        }
        temp.next.prev = null; //Gán rỗng cho prev của phần tử cuối DSLK
        temp.next = null; //Gán rỗng cho next của phần tử kề cuối DSLK
        return head; //Trả về head
    }

    //Xoa Node co data = X
    static Node dele_match_data(Node head, int x) {
        if (head == null) { //Nếu head là rỗng
            System.out.println("Empty List!");
            return head; //Trả về head
        }
        if (head.data == x) { //Nếu phần data của head bằng X
            head = front_dele(head); //Gọi hàm front_dele() và gán kết quả cho head
            return head; //Trả về head
        }
        Node temp = head.next; //Tạo đối tượng temp của lớp Node và gán phần tử tiếp theo của head cho temp
        int flag = 0; //Tạo biến cờ (flag) kiểu nguyên và gán 0 cho nó
        while (temp != null) { //Vòng lặp thực hiện khi mà temp không phải rỗng
            if (temp.data == x) { //Kiểm tra xem data của đối tượng temp hiện tại có bằng X không
                flag = 1; //Nếu bằng thì gán 1 cho cờ (flag)
                break; //Thoát khỏi vòng lặp
            }
            temp = temp.next; //Đưa temp tới Node tiếp theo
        }
        //Kiểm tra có đối tượng nào mang data X trong DSLK không (1)
        if (flag == 1) { //Nếu flag = 1 thì có tồn tại đối tượng khớp với điều kiện (1)
            temp.prev.next = temp.next; //Gán phần tử liền sau của đối tượng đó (đối tượng có data = X) cho phần next của đối tượng liền trước nó
        }
        else {
            System.out.println("Do not exist!"); //Không tồn tại đối tượng thõa điều kiện (1)
        }
        return head; //Trả về head
    }

    //Sap xep tang dan 
    static void arrange(Node head){
        Node tmp = head; //Tạo đối tượng tmp của lớp Node và gán head cho nó
        while ( tmp != null){ //Vòng lặp thứ 1 thực hiện khi tmp không phải rỗng
            Node temp = tmp.next; //Tạo đối tượng temp của lớp Node và gán phần next của tmp cho nó
            while(temp != null){ //Vòng lặp thứ 2 thực hiện khi temp không phải rỗng
                if(temp.data < tmp.data){ //Nếu phần data của temp nhỏ hơn phần data của tmp thì
                    //Đổi phần data của temp và tmp cho nhau
                    int c = temp.data; 
                    temp.data = tmp.data;
                    tmp.data = c;
                }
                temp = temp.next; //Đưa temp tới Node tiếp theo
            }
            tmp = tmp.next; //Đưa tmp tới Node tiếp theo
        }
    }

    //Sap xep giam dan 
    static void arrange2(Node head){
        Node tmp = head; //Tạo đối tượng tmp của lớp Node và gán head cho nó
        while ( tmp != null){ //Vòng lặp thứ 1 thực hiện khi tmp không phải rỗng
            Node temp = tmp.next; //Tạo đối tượng temp của lớp Node và gán phần next của tmp cho nó
            while(temp != null){ //Vòng lặp thứ 2 thực hiện khi temp không phải rỗng
                if(temp.data > tmp.data){ //Nếu phần data của temp lớn hơn phần data của tmp thì
                    //Đổi phần data của temp và tmp cho nhau
                    int c = temp.data;
                    temp.data = tmp.data;
                    tmp.data = c;
                }
                temp = temp.next; //Đưa temp tới Node tiếp theo
            }
            tmp = tmp.next; //Đưa tmp tới Node tiếp theo
        }
    }

    //Hàm thêm hàng loạt các đối tượng vào cuối DSLK
    static Node makeList( Node head){ 
        head.input(12);
        addNode(head, 61);
        addNode(head, 3);
        addNode(head, 0);
        addNode(head, 53);
        addNode(head, 44);
        return head; //Trả về head
    }

    //Hàm tìm vị trí của đối tượng mang data = X
    static void lookForNode( Node head, int x){
        Node tmp = head; Node temp = head; int count = 1; 
        while ( tmp != null){
            if ( tmp.data == x){
                //Timvitri
                while( temp != tmp){
                    count++;
                    temp = temp.next;
                }
                System.out.println("Vi tri cua " + x + " la :"+ count);
            }
            tmp = tmp.next;
        }
        return;
    }

    //Ham main thuc thi chuong trinh
    public static void main (String[] args) {
        //Tao doi tuong input de thuc hien cong viec nhan dau vao tu User
        Scanner input = new Scanner(System.in);
        Node head = new Node();
        head = makeList(head);
        System.out.print("Danh sach co san la :");
        export(head);
        int choose;
        do {
            menu();
            System.out.print("Nhap: ");
            choose = input.nextInt();
            switch (choose) {
                case 1:
                {
                    int choice;
                    do {
                        menu1();
                        System.out.print("Nhap: ");
                        choice = input.nextInt();
                        switch (choice) {
                            case 1:
                            {
                                System.out.print("\nAmounts: ");
                                int n = input.nextInt();
                                for (int i = 1; i <= n; i++) {
                                    System.out.print("\nData: ");
                                    int x = input.nextInt();
                                    head = frontadd(head,x);
                                }
                                export(head);
                                break;
                            }
                            case 2:
                            {
                                System.out.print("\nAmounts: ");
                                int n = input.nextInt();
                                System.out.print("\nViTri: ");
                                int k = input.nextInt();
                                for (int i = 1; i <= n; i++) {
                                    System.out.print("\nData: ");
                                    int x = input.nextInt();
                                    head = addtoIndex(head, x, k);
                                }
                                export(head);
                                break;
                            }
                            case 3:
                            {
                                System.out.print("\nAmounts: ");
                                int n = input.nextInt();
                                for (int i = 1; i <= n; i++) {
                                    System.out.print("\nData: ");
                                    int x = input.nextInt();
                                    head = addNode(head,x);
                                }
                                export(head);
                            }
                        }
                    } while(choice != 0);
                    break;
                }
                case 2:
                {
                    int choice;
                    do {
                        menu2();
                        System.out.print("Nhap: ");
                        choice = input.nextInt();
                        switch (choice) {
                            case 1:
                            {
                                head = front_dele(head);
                                export(head);
                                break;
                            }
                            case 2:
                            {
                                head = lastest_dele(head);
                                export(head);
                                break;
                            }
                            case 3:
                            {
                                int x;
                                System.out.print("Nhap x: ");
                                x = input.nextInt();
                                head = dele_match_data(head, x);
                                export(head);
                            }
                        }
                    } while(choice != 0);
                    break;
                }
                case 3:
                {
                    export(head);
                    break;
                }
                case 4:
                {
                    int choice;
                    do {
                        menu4();
                        System.out.print("Nhap: ");
                        choice = input.nextInt();
                        switch (choice) {
                            case 1:
                            {
                                arrange(head);
                                export(head);
                                break;
                            }
                            case 2:
                            {
                                arrange2(head);
                                export(head);
                            }
                            
                        }
                    } while(choice != 0);
                    break;
                }
                case 5:
                {
                    int x;
                    System.out.print("Nhap x: ");
                    x = input.nextInt();
                    lookForNode(head, x);
                    break;
                }
            }
        } while (choose != 0);
        input.close();

    }
}