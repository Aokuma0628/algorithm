import { promises as fs } from 'fs';

const MAX_NUM = 30;  // 10^30 = 1,073,741,824

function mainLogic(
  n: number,
  an: number[],
): void {
  let cnt = 0;
  let isFin = false;

  for (let i = 0; i < MAX_NUM; i++) {
    for (let j = 0; j < n; j++) {
      if (an[j] % 2 !== 0) {
        isFin = true;
        break;
      }
      an[j] = an[j] / 2;
    }

    if (isFin) break;
    cnt++;
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
  const n = parseInt(textArr[0], 10);
  const anStr = textArr[1].split(' ');
  const an: number[] = [];

  for (let i = 0; i < n; i++) {
    an.push(parseInt(anStr[i], 10));
  }

  mainLogic(n, an);
  return;
}

main();
