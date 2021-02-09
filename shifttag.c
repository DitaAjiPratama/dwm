/** Function to shift the current view to the left/right
 *
 * @param: "arg->i" stores the number of tags to shift right (positive value)
 *          or left (negative value)
 */

void
shifttag(const Arg *arg) {
	if(selmon->sel){
	
		Arg shifted;
	
		if(arg->i > 0) // left circular shift
			shifted.ui = (selmon->tagset[selmon->seltags] << arg->i)
			   | (selmon->tagset[selmon->seltags] >> (LENGTH(tags) - arg->i));

		else // right circular shift
			shifted.ui = selmon->tagset[selmon->seltags] >> (- arg->i)
			   | selmon->tagset[selmon->seltags] << (LENGTH(tags) + arg->i);
	
        	selmon->sel->tags = shifted.ui & TAGMASK;
        	arrange(selmon);
		view(&shifted);
	}
}
