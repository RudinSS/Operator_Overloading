#ifndef __PERSEGI_PANJANG_HPP__
#define __PERSEGI_PANJANG_HPP__
#include <iostream>
    class persegiPanjang{
        private:
            float xmax, xmin, ymax, ymin;
        public:
            persegiPanjang(float tTengahX, float tTengahY, float panjang, float lebar);
            bool operator== (persegiPanjang const &)const;
            persegiPanjang operator+ (persegiPanjang const &);
            persegiPanjang operator- (persegiPanjang const &);
            void operator++ ();
            void operator++(int);
            void operator-- ();
            void operator--(int);
            float operator[](int pilihan);
            void output();
    };
#endif