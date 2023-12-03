class tPoint
{
    private:
        int x;
        int y;
        int red;
        int blue;
        int green;
        int alpha;
        int speed_x;
        int speed_y;
    public:
        void init();
        void set_x(int ex);
        void set_y(int ex);
        int get_x();
        int get_y();
        void set_RGBA(int r, int g, int b, int a);
        int get_R();
        int get_G();
        int get_B();
        int get_A();
        void set_speed_x(int ex);
        void set_speed_y(int ex);
        int get_speed_x();
        int get_speed_y();
        int move_x();
        int move_y();
        void reflexion_x();
        void reflexion_y();
};