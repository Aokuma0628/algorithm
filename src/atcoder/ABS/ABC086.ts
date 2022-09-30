import { promises as fs } from 'fs';

function mainLogic(
  a: number,
  b: number,
): void {
  console.log('%s', (a * b % 2 === 0) ? 'Even' : 'Odd');
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
  const ab = textArr[0].split(' ');
  const a = parseInt(ab[0], 10);
  const b = parseInt(ab[1], 10);

  mainLogic(a, b);
  return;
}

main();
