import { promises as fs } from 'fs';

function mainLogic(
  a: number,
  b: number,
  c: number,
  x: number,
): void {
  let cnt = 0;
  
  for (let i = 0; i <= a; i++) {
    if ((500 * i) > x) break;
    for (let j = 0; j <= b; j++) {
      const remain = x - (500 * i + 100 * j);
      if (remain < 0) break;

      if (c >= (remain / 50)) cnt++;
    }
  }

  console.log('%d', cnt);

  return;
}


async function main(
): Promise<void> {
  let text = '';
  let textArr = [];

  try {
    text = await fs.readFile('/dev/stdin', 'utf8');
  }
  catch (err) {
    console.log(err);
    return;
  }

  textArr = text.split('\n');
  const a = parseInt(textArr[0], 10);
  const b = parseInt(textArr[1], 10);
  const c = parseInt(textArr[2], 10);
  const x = parseInt(textArr[3], 10);

  mainLogic(a, b, c, x);
  return;
}

main();
