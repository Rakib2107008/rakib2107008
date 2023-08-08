#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

class profile;
class grand_total;

class breakfast {
    int bread_cal;
    int egg_cal;
    int cake_cal;
    int fruit_cal;
    int bread_num, egg_num, cake_num, fruit_num;
    int total_cal;

public:
    void set_cal() {
        bread_cal = 70;
        egg_cal = 80;
        cake_cal = 60;
        fruit_cal = 80;
    }

    breakfast() {
        bread_num = 0;
        egg_num = 0;
        cake_num = 0;
        fruit_num = 0;
    }

    breakfast(int a, int b, int c, int d) {
        bread_num = a;
        egg_num = b;
        cake_num = c;
        fruit_num = d;
    }

    friend class grand_total;

    int calori_cal() {
        total_cal = bread_cal * bread_num + egg_cal * egg_num + cake_cal * cake_num + fruit_cal * fruit_num;
        return total_cal;
    }
};

class lunch {
    int veg_cal;
    int lentil_cal;
    int meat_cal;
    int fish_cal;
    int rice_cal;
    int total_cal1;
    int veg_quan, lentil_quan, meat_quan, fish_quan, rice_quan;

public:
    void set_cal1() {
        veg_cal = 4;    //per gram
        lentil_cal = 4; //per gram
        meat_cal = 9;
        fish_cal = 9;
        rice_cal = 4;   // per gram
    }

    lunch() {
        veg_quan = 0;
        lentil_quan = 0;
        meat_quan = 0;
        fish_quan = 0;
        rice_quan = 0;
    }

    lunch(int a, int b, int c, int d, int e) {
        veg_quan = a;
        lentil_quan = b;
        meat_quan = c;
        fish_quan = d;
        rice_quan = e;
    }

    friend class grand_total;

    int calori_cal1() {
        total_cal1 = veg_quan * veg_cal + lentil_quan * lentil_cal + meat_quan * meat_cal + fish_quan * fish_cal + rice_quan * rice_cal;
        return total_cal1;
    }
};

class dinner {
    int bread_num;
    int egg_fry;
    int veg_quan;
    int rice_quan;
    int fish_quan;
    int bread_cal;
    int egg_cal;
    int veg_cal;
    int rice_cal;
    int fish_cal;
    int total_cal2;

public:
    void set_cal2() {
        bread_cal = 70;
        egg_cal = 80;
        rice_cal = 4;   //per gram
        fish_cal = 9;
        veg_cal = 4;
    }

    dinner() {
        bread_num = 0;
        egg_fry = 0;
        veg_quan = 0;
        rice_quan = 0;
        fish_quan = 0;
    }

    dinner(int a, int b, int c, int d, int e) {
        bread_num = a;
        egg_fry = b;
        veg_quan = c;
        rice_quan = d;
        fish_quan = e;
    }

    friend class grand_total;

    int calori_cal2() {
        total_cal2 = bread_cal * bread_num + egg_cal * egg_fry + veg_cal * veg_quan + rice_cal * rice_quan + fish_cal * fish_quan;
        return total_cal2;
    }
};

class profile {
    string name;
    int age;
    string gender;
    float height;
    float weight;
    float bmi;

public:
    void set_profile() {
        cout << "Enter name:";cin>>name;
        cout << "Age:";
        cin >> age;
        cout << "Gender:";
        getchar();
        getline(cin, gender);
        cout << "Height in meter:";
        cin >> height;
        cout << "Weight in kg:";
        cin >> weight;
    }

    void display_pro() {
        cout << "Personal profile:" << endl
             << "Name: " << name << endl
             << "Age: " << age << endl
             << "Gender: " << gender << endl
             << "Height in meter: " << height << endl
             << "Weight in kg: " << weight << endl
             << "BMI: " << bmi << endl;

        if (bmi < 18.5)
            cout << "You are underweight" << endl;
        else if (bmi >= 18.5 && bmi <= 24.9)
            cout << "Your weight is normal" << endl;
        else if (bmi >= 25 && bmi <= 29.9)
            cout << "You are overweight" << endl;
        else if (bmi >= 30 && bmi <= 34.9)
            cout << "You are suffering from obesity (Class 1)" << endl;
        else if (bmi >= 35 && bmi <= 39.9)
            cout << "You are suffering from obesity (Class 2)" << endl;
        else
            cout << "You are suffering from extreme obesity (Class 3)" << endl;
    }

    friend class grand_total;
    friend void bmi(profile &);
};

class grand_total {
    int grand_cal;
    int extra_cal;

public:
    int stan_male_cal = 2500;
    int stan_female_cal = 2000;

    int calori_total(breakfast cal1, lunch cal2, dinner cal3) {
        grand_cal = cal1.total_cal + cal2.total_cal1 + cal3.total_cal2;
        return grand_cal;
    }

    void extra_cal_count(profile &ext1) {
        if (ext1.gender == "male")
            extra_cal = grand_cal - 2500;
        else
            extra_cal = grand_cal - 2000;
    }

    friend class exercise;
};

void bmi(profile &pro1) {
    pro1.bmi = pro1.weight / (pro1.height * pro1.height);
}

class exercise {
    int ext_cal;
    float num_push;
    float time_jog;
    float time_swim;
    float time_cyc;

public:
    float push_up = 1.0;      //per 1 push up
    float swimming = 20.0;   //per min
    float jogging = 12.0;     //per min
    float cycling = 25.0;     //per min

    void set_extra(grand_total &a) {
        ext_cal = a.extra_cal;
        if (ext_cal > 0) {
            cout << "You need to burn up your extra calories" << endl;
            cout << "Here are some recommendations:" << endl;
        }
    }

    void display_time() {
        if (ext_cal > 0 && ext_cal < 100) {
        cout<<"the extra consumed calori is :"<<ext_cal<<" calori and you can burn up the additional calori in the following way"<<endl;
            num_push = 0.2* ext_cal / push_up;
            time_jog = 0.8 * ext_cal / jogging;
            cout << "You can run for " << time_jog << " minutes and" << endl
                 << "you can do " << num_push << " push-ups per day" << endl;
        } else if (ext_cal >= 100 && ext_cal < 500) {
        cout<<"the extra consumed calori is :"<<ext_cal<<" calori and you can burn up the additional calori in the following way"<<endl;
            num_push = 0.05 * ext_cal / push_up;
            time_jog = 0.45* ext_cal / jogging;
            time_cyc = 0.50 * ext_cal / cycling;
            cout << "You can run for " << time_jog << " minutes and" << endl
                 << "you can do " << num_push << " push-ups per day and" << endl
                 << "you can also ride a cycle for " << time_cyc << " minutes per day" << endl;
        } else if (ext_cal >= 500) {
       cout<<"the extra consumed calori is :"<<ext_cal<<" calori and you can burn up the additional calori in the following way"<<endl;
            num_push = 0.05 * ext_cal / push_up;
            time_jog = 0.3 * ext_cal / jogging;
            time_cyc = 0.40 * ext_cal / cycling;
            time_swim = 0.25* ext_cal / swimming;
            cout << "You can run for " << time_jog << " minutes and" << endl
                 << "you can do " << num_push << " push-ups per day and" << endl
                 << "you can also ride a cycle for " << time_cyc << " minutes per day and" << endl
                 << "you can also swim for " << time_swim << " minutes per day" << endl;
        } else {
            cout << "You need to eat more to be healthy" << endl;
        }
    }

    int get_value() {
        return ext_cal;
    }
};

int main() {
    profile user_profile;
    user_profile.set_profile();
    int bread, egg, cake, fruit;
    cout<<"Enter the quantity of food that you eat in breakfast"<<endl;
    cout << "Number of bread pieces: ";
    cin >> bread;
    cout << "Number of eggs: ";
    cin >> egg;
    cout << "Number of cakes: ";
    cin >> cake;
    cout << "Number of apples: ";
    cin >> fruit;

    breakfast user_breakfast(bread, egg, cake, fruit);
    user_breakfast.set_cal();
cout<<"Enter the quantity of food that you take at lunch"<<endl;
    int veg, lentil, meat, fish, rice;
    cout << "Quantity of vegetables in grams: ";
    cin >> veg;
    cout << "Quantity of lentils in grams: ";
    cin >> lentil;
    cout << "Quantity of meat in grams: ";
    cin >> meat;
    cout << "Quantity of fish in grams: ";
    cin >> fish;
    cout << "Quantity of rice in grams: ";
    cin >> rice;

    lunch user_lunch(veg, lentil, meat, fish, rice);
    user_lunch.set_cal1();
cout<<"Enter the quantity of food that you take at dinner"<<endl;
    cout << "Number of bread pieces: ";
    cin >> bread;
    cout << "Number of eggs: ";
    cin >> egg;
    cout << "Quantity of vegetables in grams: ";
    cin >> veg;
    cout << "Quantity of rice in grams: ";
    cin >> rice;
    cout << "Quantity of fish in grams: ";
    cin >> fish;

    dinner user_dinner(bread, egg, veg, rice, fish);
    user_dinner.set_cal2();

    grand_total user_grand_total;
    
    bmi(user_profile); // Calculate BMI

    int breakfast_calories = user_breakfast.calori_cal();
    int lunch_calories = user_lunch.calori_cal1();
    int dinner_calories = user_dinner.calori_cal2();

    int total_calories = user_grand_total.calori_total(user_breakfast, user_lunch, user_dinner);
    user_grand_total.extra_cal_count(user_profile);

    exercise user_exercise;
    user_exercise.set_extra(user_grand_total);

    user_profile.display_pro();
    user_exercise.display_time();


    return 0;
}