#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int get_num_of_segments(){
	int a = 4;
	do{
		if (a<2 || a>10){
			printf("");
			printf("\ninvalid number of segments");
			printf("");
		}
		printf("\nHow many spherical segments you want to evaluate [2-10]?");
		scanf("%d", &a);
	}
	while(a<2 || a>10);
	return a;
	
}

float calculate_total_surface_area(float r, float a_h, float b_h){
	float a = sqrt(r*r - a_h*a_h);
	float b = sqrt(r*r - b_h*b_h);
	float height = a_h-b_h;
	float total_surf_area = 3.14159265359*a*a + 3.14159265359*b*b + 2*3.14159265359*r*height;
	return total_surf_area;
}

float calculate_volume(float r, float a_h, float b_h){
	float a = sqrt(r*r - a_h*a_h);
        float b = sqrt(r*r - b_h*b_h);
        float height = a_h-b_h;
	float volume_of_segs = 0.166666667*3.14159265359*height*(3*a*a+3*b*b+height*height);
	return volume_of_segs;

}

void get_radius_of_sphere_and_other_values(int f, float surf_area[], float vol[]){
	float r = 4;
	float h_a = 1;
	float h_b = 1;
	float total_surface_area = 0;
	float volume = 0;
        do{
		if ((r<=0 || h_a<=0 || h_b<=0) || (h_a>=r) || (h_b>=r) || (h_a<h_b)){
			printf("");
			printf("\ninput is invalid, please re-enter values");
			printf("");
		}

                printf("\nWhat is the radius of the sphere (R)?");
                scanf("%f", &r);
		printf("\nWhat is the height of the top area of the spherical segment (ha)?");
                scanf("%f", &h_a);
                printf("\nWhat is the height of the bottom area of the spherical segment (hb)?");
                scanf("%f", &h_b);
		printf("\nentered data: R = %f, h_a = %f,  h_b = %f ", r, h_a, h_b);
		printf("\n");
        }
        while((r<=0 || h_a<=0 || h_b<=0) || (h_a>=r) || (h_b>=r) || (h_a<h_b));
		total_surface_area = calculate_total_surface_area(r, h_a, h_b);
		volume = calculate_volume(r, h_a, h_b);
		surf_area[f] = total_surface_area;
		vol[f] = volume;
		printf("");
		printf("\ntotal surface area = %.2f, volume = %.2f", total_surface_area, volume);
		printf("\n");

}

void calculate_avg_vol_and_surface_area(float array1[], float array2[], float num_of_seg){
	float surf_area = 0;
	float vol = 0;
	float avg_surf_area = 0;
	float avg_vol = 0;
	for(int i = 0; i<num_of_seg; i++){
		surf_area+=array1[i];
		vol+=array2[i];
	}
	printf("\nTotal average results");
	avg_surf_area = surf_area/num_of_seg;
	printf("\nAverage Surface Area = %.2f", avg_surf_area);
	avg_vol = vol/num_of_seg;
	printf("\nAverage Volume = %.2f", avg_vol);
	printf("\n");
}

int main(){
	int num_of_segments = get_num_of_segments();
	float surface_area[num_of_segments];
	float volume[num_of_segments];
	for(int i = 0; i< num_of_segments; i++){
		get_radius_of_sphere_and_other_values(i, surface_area, volume);
	}
	calculate_avg_vol_and_surface_area(surface_area, volume, num_of_segments);
	
}
