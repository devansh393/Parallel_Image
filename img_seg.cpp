#include <stdio.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include <algorithm>
#include <sys/time.h>
#include <omp.h>
#include <unordered_map>

using namespace std;

#define MATCH(s) (!strcmp(argv[ac], (s)))

static const double kMicro = 1.0e-6;

int main(int argc,char **argv)
{
	int width,height;
	int pixelWidth;
	int Threshold = 3;
	int numThreads = 4;
	int seed =1 ;
	const char *filename = "input.png";
	const char *outputname = "output.png";
  	for(int ac=1;ac<argc;ac++)
	{
	    if(MATCH("-s")) {Threshold = atoi(argv[++ac]);}
	    else if(MATCH("-t")) {numThreads = atoi(argv[++ac]);}
	    else if(MATCH("-i"))  {filename = argv[++ac];}
	    else if(MATCH("-o"))  {outputname = argv[++ac];}
	    else {
	      printf("Usage: %s [-i < filename>] [-s <threshold>] [-t <numThreads>] [-o outputfilename]\n",argv[0]);
	      return(-1);
	    }
	}
  return 0;
  }