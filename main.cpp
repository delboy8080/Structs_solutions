#include <iostream>

using namespace std;
struct geo_location
{
    double longtitude;
    double latitude;
};

struct tweet
{
    string author;
    string message;
    int ID;
    unsigned long int timestamp;
    geo_location location;

};

void display_tweet_by_value(tweet tweet1)
{

    cout << endl << "Call by Value" << endl;
    cout <<"ID:"      << tweet1.ID  <<endl;
    cout <<"Message:" << tweet1.message <<endl;
    cout <<"Author:"  << tweet1.author <<endl;
    cout <<"Timestamp:"<< tweet1.timestamp<<endl;
    cout <<"location:"<< tweet1.location.latitude <<", "<< tweet1.location.longtitude << endl;

}

void display_tweet_by_reference(const tweet &tweet1)
{
    cout <<endl << "Call by Reference" << endl;
    cout <<"ID:"      << tweet1.ID  <<endl;
    cout <<"Message:" << tweet1.message <<endl;
    cout <<"Author:"  << tweet1.author <<endl;
    cout <<"Timestamp:"<< tweet1.timestamp<<endl;
    cout <<"location:"<< tweet1.location.latitude <<", "<< tweet1.location.longtitude << endl;

}

void display_tweet_array_notation(tweet arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        display_tweet_by_reference(arr[i]);
    }
}
void question1();
void question2();

int main() {

    // question1();
    question2();
    return 0;
}

void question1()
{

    tweet tweet1;
    tweet1.message = "My first tweet";
    tweet1.author = "delboy";
    tweet1.timestamp = 1709557111;
    tweet1.ID = 1;
    tweet1.location.longtitude =  -6.405957;
    tweet1.location.latitude = 53.997945;

    display_tweet_by_value(tweet1);
    display_tweet_by_reference(tweet1);

    tweet *tweets = new tweet[3];
    tweets[0] = tweet1;

    tweets[1].author = "Jack Dorsey";
    tweets[1].message = "Inviting Coworkers";
    tweets[1].timestamp = 1141217910;
    tweets[1].ID = 2;
    tweets[1].location.latitude = 37.773972;
    tweets[1].location.longtitude =-122.431297;

    tweets[2].author = "Joe Biden";
    tweets[2].message = "It's a new day in America.";
    tweets[2].timestamp = 1141218510;
    tweets[2].ID = 3;
    tweets[2].location.latitude = 37.773972;
    tweets[2].location.longtitude =-122.431297;

    cout << "Printing in main user pointer notation" <<endl;
    tweet *tweets_ptr = tweets;
    for(int i = 0; i < 3; i++)
    {
        display_tweet_by_reference(*tweets_ptr);
        tweets_ptr++;
    }

    cout << "Printing in function using array notation" <<endl;
    display_tweet_array_notation(tweets, 3);
    delete[] tweets;
}

struct Rgb
{
    float r, g, b;
    Rgb() : r(0), g(0), b(0) {} // default values (0,0,0)
    Rgb(float rr, float gg, float bb) : r(rr), g(gg), b(bb) {}
};

void display_pixel_channels(Rgb &rgb)
{
    cout << "Red: " << rgb.r <<endl;
    cout << "Green: " << rgb.g <<endl;
    cout << "Blue: " << rgb.b <<endl;

}

void red_filter(Rgb &rgb)
{
   rgb.g = rgb.b = 0;

}
void question2()
{
    Rgb whitePixel = Rgb(1.0, 1.0, 1.0);
    Rgb blackPixel(0,0,0);
    Rgb redPixel(1,0,0);
    Rgb greenPixel(0,1,0);
    Rgb bluePixel(0,0,1);
    Rgb pinkPixel(1,.6,0.8);
    Rgb magentaPixel(1,0,1);

    cout << "Original Pink pixel: "<<endl;
    display_pixel_channels(pinkPixel);
    cout << "\n\n";
    red_filter(pinkPixel);
    cout << "Pink pixel after applying red filter: "<<endl;
    display_pixel_channels(pinkPixel);

}