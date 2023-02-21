class Student(object):
    #self.temp=1 chỉ được khai báo trong phương thức khởi tạo
    __temp=1#bien thuoc doi tuong
    #Ham khoi tao
    def __init__(self,soTheCanCuoc=0,tenHV="",NamSinh=2003,dsMonhoc=[]):
        self.__soTheCanCuoc=soTheCanCuoc
        self.tenHV=tenHV
        self.NamSinh=NamSinh
        self.dsMonhoc=dsMonhoc
    #Phuong thuc
    def themMonHoc(self,tenmon):
        self.dsMonhoc.append(tenmon)
    def hienThi(self):
        print(self.__soTheCanCuoc,self.tenHV,self.NamSinh,len(self.dsMonhoc))
sv1=Student(0o123456,"Nguyen Van A",2003,"toan")
sv1.hienThi()
sv2=Student(0o123456,"Nguyen Van A",2003,"toan")
sv2.__soTheCanCuoc=5

print(sv1.tenHV)