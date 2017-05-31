function addClassName(node,name){
	var className=node.getAttribute("class");
	var newClassName;
	if(className){
		newClassName=className+" "+name;
	}else{
		newClassName=name;
	}
	node.setAttribute("class",newClassName);
}