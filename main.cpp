#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>


using namespace std;

int FirstMainMenu();
void MenuMovie();
void MenuDirector();

class Movie{
private:
    string Name;
    string Type;
    string Director;
    string Summary;
    double Point;
    int Year;



public:


    void setName(string M_Name){
        Name=M_Name;
    }

    string getName(void){
        return Name;
    }

    void setType(string M_Type){
        Type=M_Type;
    }

    string getType(void){
        return Type;
    }

    void setDirector(string M_Director){
        Director=M_Director;
    }

    string getDirector(void){
        return Director;
    }

    void setSummary(string M_Summary){
        Summary=M_Summary;
    }

    string getSummary(){
        return Summary;
    }

    void setPoint(double M_Point){
        Point=M_Point;
    }

    double getPoint(void){
        return Point;
    }

    void setYear(int M_Year){
        Year=M_Year;
    }

    int getYear(){
        return Year;
    }


    void display(){

        cout<< "The Name of the movie--------------->" <<Name<<endl;
        cout<< "The Type of the movie--------------->" <<Type<<endl;
        cout<< "The Summary of the movie------------>" <<Summary<<endl;
        cout<< "The Director of the movie----------->" <<Director<<endl;
        cout<< "The point of IMDB of the movie------>" <<Point<<endl;
        cout<< "The vision year of the movie-------->\n" <<Year<<endl;


    };


};

class Directors{
private:
    string FullName;
    string Movies;
    int Age;


public:

    void setFullName(string D_FullName){
        FullName=D_FullName;
    }

    string getFullName(){
        return FullName;
    }

    void setMovies(string D_Movies){
        Movies=D_Movies;
    }

    string getMovies(){
        return Movies;
    }

    void setAge(int D_Age){
        Age=D_Age;
    }

    int getAge(){
        return Age;
    }


    void display(){

        cout<< "The director name is------------------->" <<FullName<<endl;
        cout<< "The movies of the director------------->" <<Movies<<endl;
        cout<< "The age of the director---------------->" <<Age<<endl;


    };



};

Movie M[20];
Directors D[20];

int display_movie_information(int i){

    cout<< "The Name of the movie--------------->" <<M[i].getName()<<endl;
    cout<< "The Type of the movie--------------->" <<M[i].getType()<<endl;
    cout<< "The Director of the movie----------->" <<M[i].getDirector()<<endl;
    cout<< "The point of IMDB of the movie------>" <<M[i].getPoint()<<endl;
    cout<<"  "<<endl;
    cout<< "The vision year of the movie-------->" <<M[i].getYear()<<endl;
    cout<<"  "<<endl;
    cout<< "The Summary of the movie------------>" <<M[i].getSummary()<<endl;
    cout<<"  "<<endl;

    cout << "***************************************************"<<endl<<endl;



    return i;

}

int display_director_information(int i){

    cout<< "The director name is------------------->" <<D[i].getFullName()<<endl;
    cout<< "The movies of the director------------->" <<D[i].getMovies()<<endl;
    cout<< "The age of the director---------------->" <<D[i].getAge()<<"\n"<<endl;


    return i;

}

int FirstMainMenu(){

    int x[5];
    cout<< "" <<endl;
    cout << "Wellcome To The Little IMDB Program...\n " <<endl;
    cout << "---1---1---1---1---Movies---1---1---1---1---" <<endl;
    cout << "---2---2---2---2--Directors--2---2---2---2---" <<endl;
    cout << "Press 3 For To Exit"<<endl;

    cout<< "" <<endl;

    cout << "***************************************************"<<endl<<endl;

    cin>>x[0];

    switch(x[0]){

        case 1:{    MenuMovie();       break;        }

        case 2:{    MenuDirector();    break;        }

        case 3:{    exit(1);           break;        }

    }


}

void MenuMovie(){
    cout << "\nHi Guys This Is The Movie Menu....\n" <<endl;
    cout << "Press the number for choose the source....\n"<<endl;
    cout << "1---Sort The Movies From Small To Large with imDB point-----1" <<endl;
    cout << "2---Find the movies with Name-------------------------------2" <<endl;
    cout << "3---Find the movie with the product Year--------------------3" <<endl;
    cout << "4---Random a Movie if don't have a idea---------------------4" <<endl;
    cout << "5---For back to main menu-----------------------------------5" <<endl;

    cout<< "" <<endl;

    cout << "***************************************************"<<endl<<endl;

    int c[10];
    string Search_Name;
    cin>> c[0];

    switch(c[0])
    {


        case 1:{
            cout << "Enter an number how many do you want to sort: ";

            cin>>c[1];

            cout<<""<<endl;

            cout << "***************************************************"<<endl<<endl;


            for(int j=0; j<c[1] ; j++){
                display_movie_information(j);

            }

            MenuMovie();

            break;
        }




        case 2:{
            cout << "Enter the name which do you want to find-->";


            cin.ignore();
            getline(cin,Search_Name);


            for(int i=0 ; i<=5 ; i++){

                if(Search_Name == M[i].getName()){

                    cout << "This movie which you have search"<<endl;

                    display_movie_information(i);

                    cout << "if you want to see more information with this movies director \n Press 1" <<endl;
                    cin >>c[2];
                    if(c[2]==1){
                        display_director_information(i);
                    }

                    MenuMovie();

                }

                else if(i==5) {cout << "Its wrong pls try again " <<endl;
                    MenuMovie();
                }

            }

            break;
        }




        case 3:{
            int Fyear,Syear;
            cout << "Please enter the first year: " <<endl;
            cin >> Fyear;

            cout<<" "<<endl;

            cout << "Please enter the second year: " <<endl;
            cin >> Syear;

            cout<<" "<<endl;

            cout << "***************************************************"<<endl<<endl;

            for(;Fyear<=Syear;Fyear++){
                for(int i=0;i<6;i++){

                    if(Fyear==M[i].getYear()){


                        display_movie_information(i);




                    }



                }



            }

            MenuMovie();

            break;
        }



        case 4:{

            int random_number;
            cout << "Random movie is coming have fun..." <<endl<<endl;;

            srand(time(0));
            random_number = (rand () % 6) ;

            cout << "***************************************************"<<endl<<endl;

            display_movie_information(random_number);



            MenuMovie();

            break;
        }



        case 5:{

            cout<< "" <<endl;

            cout << "***************************************************"<<endl<<endl;

            FirstMainMenu();

            break;
        }

    }

}

void MenuDirector(){

    int x[5];


    cout << "\nHi Guys This Is The Director Menu...\n" <<endl;
    cout << "Press the number for choose the source...\n"<<endl;
    cout << "1---Sort The Directors From Small To Large with imDB point-----1" <<endl;
    cout << "2---Find The Directors with their name-------------------------2" <<endl;
    cout << "3---Random a Director------------------------------------------3" <<endl;
    cout << "4---For Add a Director information-----------------------------4" <<endl;
    cout << "5---For back to main menu--------------------------------------5" <<endl;

    cout<< "" <<endl;

    cout << "***************************************************"<<endl<<endl;


    cin>>x[1];

    switch(x[1]){

        case 1:{

            cout << "Enter an number how many do you want to sort: ";
            cin>>x[2];

            cout << "***************************************************"<<endl<<endl;

            for(int i=0;i<x[2];i++){

                display_director_information(i);


                cout << "***************************************************"<<endl<<endl;

            }

            MenuDirector();

            break;
        }


        case 2:{
            string Search_D_Name;
            cout << "Enter an Director Name " <<endl;

            cin.ignore();
            getline(cin,Search_D_Name);


            for(int i=0;i<6;i++){
                if(Search_D_Name==D[i].getFullName()){

                    display_director_information(i);

                    cout << "1-\n   2-\n    3-" <<endl;

                    cin>>x[3];

                    if(x[3]=1){

                        cout << "1. movie information" <<endl;
                    }else if(x[3]=2){

                        cout << "2. movie information" <<endl;
                    }else if(x[3]=3){
                        cout  << "3. movie information" <<endl;

                    }

                }

            }

            MenuDirector();

            break;
        }



        case 3:{

            int random_no;

            cout << "Random director is coming have fun  " <<endl<<endl;

            cout << "***************************************************"<<endl<<endl;

            srand(time(0));
            random_no= (rand () % 6) ;

            display_director_information(random_no);

            cout << "***************************************************"<<endl<<endl;

            MenuDirector();


            break;
        }


        case 4:{

            cout << "To be continune... " <<endl;

            MenuDirector();

            break;
        }


        case 5:{

            FirstMainMenu();

            break;

        }
    }

}

int main(){

    {

        M[0].setName("The Shawshank Redemption\n");
        M[0].setType("Crime, Drama\n");
        M[0].setDirector("Frank Darabont\n");
        M[0].setSummary("Two imprisoned men bond over a number of years, finding solace and eventual redemption through acts of common decency.\n");
        M[0].setPoint(9.3);
        cout<<"  "<<endl;
        M[0].setYear(1994);

        D[0].setFullName("Frank Darabont\n");
        D[0].setMovies("The Green Mile,\n The Mist,\n The Majestic,\n A Nightmare On Elm Street 3: Dream Warriors,\n Buried Alive,\n The Blob,\n The Fly 2,\n Marry Shelley's Frankenstein,\n King Kong,\n Two-Fisted Tales, The Woman In The Room,\n The United Monster Talent Agency.\n ");
        D[0].setAge(54);


        M[1].setName("The Godfather\n");
        M[1].setType("Crime, Drama\n");
        M[1].setDirector("Francis Ford Coppola");
        M[1].setSummary("The aging patriarch of an organized crime dynasty transfers control of his clandestine empire to his reluctant son.\n");
        M[1].setPoint(9.2);
        cout<<"  "<<endl;
        M[1].setYear(1972);

        D[1].setFullName("Francis Ford Coppola\n");
        D[1].setMovies("Apo calypse Now,\n The Godfather Part 2,\n Bram Stoker's Dracula,\n The Conversation,\n The Godfather Part 3,\n The Outsiders,\n Tetro, Rumble Fish,\n Twixt, The Cotton Club,\n The Rain People,\n Youth Without Youth,\n The Rainmaker,\n One From The Heart,\n Tucker: The Man And His Dream,\n Patton,\n Dementia 13,\n Peggy Sue Got Married,\n Jack, American Graffiti,\n Apocalypse Now Redux,\n New York Stories,\n The Virgin Suicides,\n Captain EO,\n You're Big Boy Now,\n Finian's Rainbow,\n Gardens Of Stone,\n Battle Beyond The Sun,\n Tonight For Sure,\n The Great Gatsby,\n The Bellboy and the Playgirls,\n Is Paris Burning?,\n Marry Shelley's Frankenstein,\n Supernova,\n The Terror,\n The Junky's Christmas,\n Don Juan DeMarco,\n This Property Is Condemned,\n The Way We Were,\n Nebo Zovyot,\n Lanli Loa- The Passage,\n The Florentine.\n ");
        D[1].setAge(75);


        M[2].setName("Schindler's List\n");
        M[2].setType("Biography, Drama, History\n");
        M[2].setDirector("Steven Spielberg\n");
        M[2].setSummary("In Poland during World War II, Oskar Schindler gradually becomes concerned for his Jewish workforce after witnessing their persecution by the Nazis.\n");
        M[2].setPoint(8.9);
        cout<<"  "<<endl;
        M[2].setYear(1993);

        D[2].setFullName("Steven Spielberg\n");
        D[2].setMovies("E.T. The Extra-Terrestrial,\n Jaws, Schindler's List,\n Raiders Of The Lost Ark,\n Bridge Of Spies,\n Saving Private Ryan,\n Jurassic Park,\n Closer Encounters Of The Third Kind,\n A.I. Artificial Intelligence,\n Indiana Jones And The Temple Of Doom,\n Indiana Jones And The Kingdom Of The Crystal Skull,\n Indiana Jones And The Last Crusade,\n Catch Me If You Can,\n Duel,\n War Horse,\n The Lost World: Jurassic Park,\n Munich,\n Hook,\n The Advantures Of Tintin: The Secret Of The Unicorn,\n The Color Purple,\n War Of The Worlds,\n Empire Of The Sun,\n The Terminal,\n The BGF,\n Lincoln,\n The Sugarland Express,\n Amistad,\n Poltergeist,\n The Goonies,\n Always,\n 1941,\n Super 8,\n Twilight Zone: The Movie,\n The Hundred-Foot Journey,\n Firelight,\n Letters From Iwo Jima,\n Something Evil,\n Amblin',\n An American Tail: Fievel Goes West,\n Flags Of Our Fathers,\n Night Skies,\n Memoirs Of A Geisha,\n Casper,\n Twister,\n Double Dare,\n The Advantures Of Tintin: Prisoners Of The Sun,\n We're Back! A Dinosaur's Story.\n");
        D[2].setAge(72);


        M[3].setName("Pulp Fiction\n");
        M[3].setType("Crime, Drama\n");
        M[3].setDirector("Quentin Tarantino\n");
        M[3].setSummary("The lives of two mob hit men, a boxer, a gangster's wife, and a pair of diner bandits intertwine in four tales of violence and redemption.\n");
        M[3].setPoint(8.9);
        cout<<"  "<<endl;
        M[3].setYear(1994);

        D[3].setFullName("Quentin Tarantino\n");
        D[3].setMovies("The Hateful Eight,\n Django Unchained,\n Killbill Volume 1,\n Killbill Volume 2,\n Grindhouse,\n Reservoir Dogs,\n Inglourious Basterds,\n Death Proof,\n From Dusk till Dawn,\n True Romance,\n Jackie Brown,\n Four Rooms,\n Planet Terror,\n Natural Born Killers,\n Sin City,\n Killbill Vol 3,\n My Best Friend's Birtday,\n Desperado,\n From Dusk till Dawn 2: Texas Blood Money,\n Curdled,\n Little Nicky,\n Sukiyaki Western Django,\n Destiny Turns On The Radio,\n Eddie Presley,\n Double Dare,\n Iron Monkey,\n Dance Me To The End Of Love,\n Restoration Dogs,\n Somebody To Love,\n The Coriolis Effect.\n ");
        D[3].setAge(50);


        M[4].setName("The Lord of the Rings: The Return of the King\n");
        M[4].setType("Adventure, Drama, Fantasy\n");
        M[4].setDirector("Peter Jackson\n");
        M[4].setSummary("Gandalf and Aragorn lead the World of Men against Sauron's army to draw his gaze from Frodo and Sam as they approach Mount Doom with the One Ring.\n");
        M[4].setPoint(8.9);
        cout<<"  "<<endl;
        M[4].setYear(2003);

        D[4].setFullName("Peter Jackson\n");
        D[4].setMovies("The Lord of the Rings: The Fellowship of the Ring,\n The Lord of the Rings: The Two Towers,\n The Lord of the Rings: The Return of the King,\n King Kong,\n The Hobbit: The Desolation Of Smaug,\n The Hobbit: The Battle Of The Five Armies,\n The Hobbit: An Unexpected Journey,\n The Lovely Bones,\n Bad Taste,\n Dead Alive,\n Heavenly Creatures,\n Meet The Feebles,\n The Frighteners,\n The Advantures Of Tintin: The Secret Of The Unicorn,\n The Advantures Of Tintin: Prisoners Of The Sun,\n Forgotten Silver,\n District 9,\n Halo,\n West Of Memphis,\n Crossing The Line,\n Jack Brown Genius.\n");
        D[4].setAge(52);


        M[5].setName("Test\n");
        M[5].setType("Test Type\n");
        M[5].setDirector("Test Director\n");
        M[5].setSummary("Test Summary\n");
        M[5].setPoint(5.0);
        cout<<"  "<<endl;
        M[5].setYear(2016);

        D[5].setFullName("Test Name\n");
        D[5].setMovies("Test Movies\n");
        D[5].setAge(20);

    }

    FirstMainMenu();

    return 0;

}
