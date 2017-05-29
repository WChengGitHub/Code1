function prepareSlideshow(){

	if(!document.getElementById)
		return false;
	if(!document.getElementsByTagName)
		return false;
	if(!document.getElementById("preview"))
		return false;
	if(!document.getElementById("linkedList"))
		return false;
	
	var preview=document.getElementById("preview");
	preview.style.position="absolute";
	preview.style.left="0px";
	preview.style.top="0px";
	
	var linkedList=document.getElementById("linkedList");
	var links=linkedList.getElementsByTagName("a");
	
	links[0].onmouseover=function(){
		moveElementById("preview",-100,0,10);
	}
	links[1].onmouseover=function(){
		moveElementById("preview",-200,0,10);
	}
	links[2].onmouseover=function(){
		moveElementById("preview",-300,0,10);
	}
}
addLoadEvent(prepareSlideshow);