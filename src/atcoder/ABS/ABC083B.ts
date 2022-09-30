import { promises as fs } from 'fs';

function mainLogic(
  n: number,
  a: number,
  b: number,
): void {
  let ans = 0;

  for (let i = 1; i <= n; i++) {
    let val = i;
    let digit = 0;
    let sum = 0;

    while (val > 0) {
      digit++;
      val = Math.floor(val / 10);
    }

    for (let j = 0; j < digit; j++) {
      const num = (j === 0) ? i : Math.floor(i / (10 ** j));
      const remain = num % 10;
      sum += remain;
    }

    if (a <= sum && sum <= b) ans += i;
  }

  console.log('%d', ans);

  return;
}


async function main(
): Promise<void> {
  let text = '';
  let textArr: string[] = [];

  try {
    text = await fs.readFile('/dev/stdin', 'utf8');
  }
  catch (err) {
    console.log(err);
    return;
  }

  textArr = text.split(' ');
  const n = parseInt(textArr[0], 10);
  const a = parseInt(textArr[1], 10);
  const b = parseInt(textArr[2], 10);


  mainLogic(n, a, b);
  return;
}

main();
