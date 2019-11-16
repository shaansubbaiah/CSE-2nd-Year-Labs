class Demo<T, U> {
    T obj1;
    U obj2;

    Demo(T obj1, U obj2){
        this.obj1 = obj1;
        this.obj2 = obj2;
    }

    void print(){
        System.out.println(obj1+"\n"+obj2);
    }
}

class Main {
    public static void main(String args[]){
        Demo<String, Integer> d = new Demo<String, Integer>("Seven", 7);
        d.print();
    }
}
