function getNextElement(node){
	var nextElement=node.nextSibling;
	if(nextElement.nodeType===1){
		return nextElement;
	}
	if(nextElement){
		return getNextElement(nextElement);
	}
	return null;
}