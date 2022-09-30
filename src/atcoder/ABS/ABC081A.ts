import { promises as fs } from 'fs';

function mainLogic(
  s: number,
): void {
  let cnt = 0;
  for (let i = 0; i < 3; i++) {
    if (s & (1 << i)) cnt++;
  }
  console.log('%d', cnt);

  return;
}


async function main(
): Promise<void> {
  let text = '';

  try {
    text = await fs.readFile('/dev/stdin', 'utf8');
  }
  catch (err) {
    console.log(err);
    return;
  }

  const s = parseInt(text, 2);

  mainLogic(s);
  return;
}

main();
