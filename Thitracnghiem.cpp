#include <iostream>
#define MaxOfSubjects 300
#define MaxOfClasses 500
using namespace std;
// Điểm thi & danh sách điểm thi
struct DiemThi  
{
    char maMonHoc[16];
    float diemThi;
};
struct nodeDiemThi  // Danh sách liên kết đơn Điểm thi
{
    DiemThi score;
    nodeDiemThi *next;
};
typedef nodeDiemThi *PtrDT;
void KhoiTao_PtrDT(PtrDT &First)
{
    First = NULL;
}
// Môn học và Danh sách môn học
struct MonHoc
{
    char maMonHoc[16], tenMonHoc[51];
};
struct DanhSachMonHoc // mảng con trỏ
{
    int n{0};
    MonHoc *nodes[MaxOfSubjects];
};
typedef DanhSachMonHoc ListMH;
// Sinh viên và Danh sách sinh viên
struct SinhVien
{
    char MSSV[11], ho[21], ten[16];
    bool phai; // male: 0     female: 1
    char password[20];
    PtrDT danhSachDiemThi;
};
struct nodeSinhVien // Danh sách liên kết đơn Sinh viên
{
    SinhVien x;
    nodeSinhVien *next;
};
typedef nodeSinhVien* PtrSV;
void KhoiTao_PtrSV(PtrSV &First) // Khởi tạo danh sách liên kết SV
{
    First = NULL;
}
// Lớp học và danh sách lớp học
struct LopHoc
{
    char maLop[16], tenLop[16],nienkhoa[10];
    PtrSV First;
};
struct DanhSachLopHoc // mảng con trỏ
{
    int n{0};
    LopHoc *nodes[MaxOfClasses];
};
typedef DanhSachLopHoc ListLH;
// Câu hỏi và danh sách câu hỏi
struct CauHoi
{
    //Id la so nguyen duong
    char ID[16], maMonHoc[16];
    unsigned answer;                            // 1 || 2 || 3 || 4
    char *ans1, *ans2, *ans3, *ans4, *question; // câu hỏi & 4 đáp án
};
struct DanhSachCauHoi // cây nhị phân tìm kiếm
{
    CauHoi question;
    DanhSachCauHoi *left;
    DanhSachCauHoi *right;
};
typedef DanhSachCauHoi *TreeCH;
int main()
{
    cout << "Hello world!\n";
    return 0;
}