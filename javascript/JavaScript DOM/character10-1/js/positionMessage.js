function positionMessage(){
	if(!document.getElementById){
		return false;
	}
	var message=document.getElementById("message");
	message.style.position="relative";
	message.style.left="50px";
	message.style.top="100px";
	//setTimeout("moveMessage()",500);
	moveElement("message",100,200);
}
function moveElement(messageId,final_left,final_right){
	var message=document.getElementById(messageId);
	var left=parseInt(message.style.left);
	var top=parseInt(message.style.top);
	var x_pos;
	var y_pos;
	if(left===final_left&&top==final_right){
		return false;
	}
	if(left<final_left){
		left++;
	}
	if(top<final_right){
		top++;
	}
	
	x_pos=left+"px";
	y_pos=top+"px";
	
	message.style.left=x_pos;
	message.style.top=y_pos;
	
	setTimeout("moveElement('"+messageId+"',"+final_left+","+final_right+")",100);
}
function moveMessage(){
	var message=document.getElementById("message");
	var left=parseInt(message.style.left);
	var top=parseInt(message.style.top);
	var x_pos;
	var y_pos;
	if(left===100&&top==200){
		return false;
	}
	if(left<100){
		left++;
	}
	if(top<200){
		top++;
	}
	
	x_pos=left+"px";
	y_pos=top+"px";
	
	message.style.left=x_pos;
	message.style.top=y_pos;
	
	setTimeout("moveMessage()",100);
}
addLoadEvent(positionMessage);