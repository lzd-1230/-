//��ͼ������
//1.����				�����ռ� 
2.����						
3.��ʾ 

//loadimage(&���飬��ͼƬλ�á�)     	ͼƬ����
//���غܶ��ʱ����ѭ��
/*ͼƬ���غ���
void loadimg(){
int i;
char Path[128];
for(i=0;i<n;i++){
	sprintf(Path,"images\\%d.bmp",i+1);
	loadimage(&img[i],"i+1.bmp");	
}
} */
//�����ﶯ����forѭ��������ͼƬ(putimage����)
/*
void roll(){
	int move=0;
	putimage(0,0,&img_y[i]);			//������+ͼƬλ�ã� 
	
}*/
//������ƶ� 
int px=0;
int py=0;
putimage(0,0,&bk);
//��ȡ�����ĺ���scanf getch getchar cin
//������getch��Ϊ������ȥ�Ϳ����̻�ò����ûس�
//��ȡ������ʱ��Ҫ�ж���û�а�������Ȼû�а�����ʱ���һֱ�����ǣ�
if(hit()){
	switch(getch()){
		//wasd  ����任  		k�����ͷ� 
		case'w':py=py-5;
		break;
		case'a':px=px-5;
		break;
		case's'py=py-5;
		break;
		case'd'px=px+5;
		break;
		case'w':;						//��ɫ�Ķ��������ܶ��� ��ɫ�����ͷ� 
	}
} 
//���ܵ��ͷ�->�ӵ�7��ͼƬ���ŵ���23��
while(move<23){
	draw();
	move++;	
} move=0;								//��ԭ 
