//贴图三部曲
//1.定义				创建空间 
2.加载						
3.显示 

//loadimage(&数组，“图片位置”)     	图片加载
//加载很多的时候用循环
/*图片加载函数
void loadimg(){
int i;
char Path[128];
for(i=0;i<n;i++){
	sprintf(Path,"images\\%d.bmp",i+1);
	loadimage(&img[i],"i+1.bmp");	
}
} */
//让人物动起来for循环滚动放图片(putimage函数)
/*
void roll(){
	int move=0;
	putimage(0,0,&img_y[i]);			//（坐标+图片位置） 
	
}*/
//人物的移动 
int px=0;
int py=0;
putimage(0,0,&bk);
//获取按键的函数scanf getch getchar cin
//我们用getch因为它按下去就可立刻获得不用敲回车
//获取按键的时候要判断有没有按键（不然没有按键的时候就一直卡在那）
if(hit()){
	switch(getch()){
		//wasd  坐标变换  		k技能释放 
		case'w':py=py-5;
		break;
		case'a':px=px-5;
		break;
		case's'py=py-5;
		break;
		case'd'px=px+5;
		break;
		case'w':;						//角色的动画：技能动画 角色技能释放 
	}
} 
//技能的释放->从第7张图片播放到第23张
while(move<23){
	draw();
	move++;	
} move=0;								//还原 
