#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

pthread_mutex_t ugly_gun = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t bad_gun = PTHREAD_MUTEX_INITIALIZER;

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

#define BOLD    "\033[1m"       /* Bold */
#define UNDERLINE "\033[4m"     /* Underline */
#define BLINK    "\033[5m"      /* Blink */
#define REVERSE  "\033[7m"      /* Reverse color */
#define HIDDEN   "\033[8m"      /* Hidden */


typedef struct s_cowboy
{
	char			*name;
	unsigned long	reaction_time;
	pthread_t		thread;
}				t_cowboy;

void	*action(void *data)
{
	t_cowboy cowboy;

	cowboy = *(t_cowboy *)data;
	// How fast cowboy is
	printf("%s reaction time: "BOLD GREEN" %lu\n"RESET"",
			 cowboy.name, cowboy.reaction_time);
	usleep(cowboy.reaction_time);

	if (!strcmp(cowboy.name, "ugly"))
		pthread_mutex_lock(&ugly_gun);
	else
		pthread_mutex_lock(&bad_gun);
	printf("%s has taken his own gun \n", cowboy.name);

	//I wanna take the other gun
	//DEADLOCK
	if (!strcmp(cowboy.name, "ugly"))
		pthread_mutex_lock(&bad_gun);
	else
		pthread_mutex_lock(&ugly_gun);
	
	//the killer will reach to this position
	printf(BOLD RED "%s " RESET "killed the other\n", cowboy.name);
	exit(EXIT_SUCCESS);
	return NULL;
}


int main()
{
	srand(time(NULL) * getpid());
	//temporizador
	signal(SIGALRM, exit);
	alarm(5);
	///////////////////
	t_cowboy	ugly = {"ugly", rand() % 10000};
	t_cowboy	bad = {"bad", rand() % 10000};

	pthread_create(&ugly.thread, NULL, action, &ugly);
	pthread_create(&bad.thread, NULL, action, &bad);

	pthread_join(ugly.thread, NULL);
	pthread_join(bad.thread, NULL);

	return 0;
}