/*
 * Verify that the statement following an unused label
 * is not discarded with the label.
 */

static int bad(int a, int b)
{
	int r = 0;

start:
	r += a;
	r += b;

	if (!r)
		goto start;
	return r;
}

/*
 * check-name: label-stmt-dropped
 * check-command: test-linearize $file
 *
 * check-output-ignore
 * check-output-contains: add
 * check-output-contains: %arg1
 */
