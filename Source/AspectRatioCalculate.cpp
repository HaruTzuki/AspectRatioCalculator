#include <iostream>

using namespace std;

class AspectRatio
{
public:
    AspectRatio();
    double TransformTo16_9(double newWidth);
    double TransformTo4_3 (double newWidth);
    double TransformFree(double originalHeight, double originalWidth, double newWidth);
};

AspectRatio::AspectRatio() {}

double AspectRatio::TransformTo16_9(double newWidth)
{
    double asprat = 16.0 / 9.0;
    return newWidth / asprat;
}

double AspectRatio::TransformTo4_3(double newWidth)
{
    double asprat = 4.0 / 3.0;
    return newWidth / asprat;
}

double AspectRatio::TransformFree(double originalHeight, double originalWidth, double targetWidth)
{
    return (originalHeight / originalWidth) * targetWidth;
}


int main()
{
    double newWidth;
    double newHeight;
    double originalWidth;
    double originalHeight;
    int mode;
    char c;
    AspectRatio a;

    cout<<"Welcome to Aspect Ratio Calculator"<<endl;
    cout<<"What to you want to transform?"<<endl;
    cout<<"1) An image with 16:9 ratio"<<endl;
    cout<<"2) An image with 4:3 ratio"<<endl;
    cout<<"3) An simple image"<<endl;
    cin >> mode;
    if (mode == 1)
    {
        cout<<"Please give us your new Width (In pixel)"<<endl;
        cin>>newWidth;
        try
        {
            newHeight = a.TransformTo16_9(newWidth);
            cout<<"The new dimensions of your image is:\nWidth: "<<newWidth<<"px\nHeight: " <<newHeight<<"px"<<endl;
        }
        catch(int e)
        {
            cout<<"Something goes wrong."<<endl;
        }
    }
    else if (mode == 2)
    {
        cout<<"Please give us your new Width (In pixel)"<<endl;
        cin>>newWidth;
        try
        {
            newHeight = a.TransformTo4_3(newWidth);
            cout<<"The new dimensions of your image is:\nWidth: "<<newWidth<<"px\nHeight: " <<newHeight<<"px"<<endl;
        }
        catch(int e)
        {
            cout<<"Something goes wrong."<<endl;
        }
    }
    else if (mode == 3)
    {
    	try
    	{
    		cout<<"Please give us your new Original Height (In pixel)"<<endl;
    		cin>>originalHeight;
    		cout<<"Please give us your new Original Width (In pixel)"<<endl;
    		cin>>originalWidth;
    		cout<<"Please give us your new Width (In pixel)"<<endl;
    		cin>>newWidth;
    		newHeight = a.TransformFree(originalHeight, originalWidth, newHeight);
    		cout<<"The new dimensions of your image is:\nWidth: "<<newWidth<<"px\nHeight: " <<newHeight<<"px"<<endl;
    	}
    	catch(int e)
    	{
    		cout<<"Something goes wrong."<<endl;
    	}
    }
    else
    {
        cout<<"Nothing happened"<<endl;
    }

    cout<<"Press any button to close"<<endl;
    cin>>c;
    return 0;
}
