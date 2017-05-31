function moveElementById(elementID,final_x,final_y,interval){
	if(!document.getElementById)
		return false;
	if(!document.getElementById(elementID))
		return false;
		
	var element=document.getElementById(elementID);
	if(element.movement){
		clearTimeout(element.movement);
	}
	if(!element.style.left){
		element.style.left="0px";
	}
	if(!element.style.top){
		element.style.top="0px";
	}
	var current_x=element.style.left;
	var current_y=element.style.top;
	
	var x=parseInt(current_x);
	var y=parseInt(current_y);
	
	if(x==final_x&&y==final_y){
		return true;
	}
	if(x<final_x){
		var dist=Math.ceil((final_x-x)/10);
		x=x+dist;
	}
	if(x>final_x){
		var dist=Math.ceil((x-final_x)/10);
		x=x-dist;
	}
	if(y<final_y){
		var dist=Math.ceil((final_y-y)/10);
		y=y+dist;
	}
	if(y>final_y){
		var dist=Math.ceil((y-final_y)/10);
		y=y-dist;
	}
	
	element.style.left=x+"px";
	element.style.top=y+"px";
	
	element.movement=setTimeout("moveElementById('"+elementID+"',"+final_x+","+final_y+")",interval);
}