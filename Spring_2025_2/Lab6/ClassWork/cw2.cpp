#include <iostream>
using namespace std;

class MediaFile {
    protected:
        string filePath;
        double fileSize;
    public:
        MediaFile(string path, double size) : filePath(path), fileSize(size) {}
        virtual void play() {
            cout << "Playing media: " << filePath << endl;
        }
    
        virtual void stop() {
            cout << "Stopping media: " << filePath << endl;
        }
    
        virtual ~MediaFile() {}
};
    
class VisualMedia : virtual public MediaFile {
    public:
        VisualMedia(string path, double size) : MediaFile(path, size) {}
        void display() {
            cout << "Displaying visual media: " << filePath << endl;
        }
};
    
class AudioMedia : virtual public MediaFile {
    public:
        AudioMedia(string path, double size) : MediaFile(path, size) {}
};

class VideoFile : public VisualMedia, public AudioMedia {
    public:
        VideoFile(string path, double size) : MediaFile(path, size), VisualMedia(path, size), AudioMedia(path, size) {}
    
        void play() override {
            cout << "Playing video file: " << filePath << endl;
        }
    
        void stop() override {
            cout << "Stopping video file: " << filePath << endl;
        }
    
        ~VideoFile() {}
};

int main() {
        VideoFile video("movie.mp4", 1500.0);
        video.play();
        video.display();
        video.stop();
}
    