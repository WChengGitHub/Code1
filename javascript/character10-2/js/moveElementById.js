function moveElementById(elementID,final_x,final_y,interval){
	if(!document.getElementById)
		return false;
	if(!document.getElementById(elementID))
		return false;
		
	var element=document.getElementById(elementID);
	
	var current_x=element.style.left;
	var current_y=element.style.top;
	
	var x=parseInt(current_x);
	var y=parseInt(current_y);
	
	if(x==final_x&&y==final_y){
		return true;
	}
	if(x<final_x){
		x++;
	}
	if(x>final_x){
		x--;
	}
	if(y<final_y){
		y++;
	}
	if(y>final_y){
		y--;
	}
	
	element.style.left=x+"px";
	element.style.top=y+"px";
	
	setTimeout("moveElementById('"+elementID+"',"+final_x+","+final_y+")",interval);
}